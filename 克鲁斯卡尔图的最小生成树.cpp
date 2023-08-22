#define Maximum 1000
#define Biggest 100000000

typedef struct EdgeListNode{
    int adjId;
    int weight;
    EdgeListNode* next;
};

typedef struct VertexListNode{
    int data;
    EdgeListNode* firstadj;
};

typedef struct GraphAdjList{
    int vertexnumber;
    int edgenumber;
    VertexListNode vertextlist[Maximum];
};

typedef struct MiniTreeEdge {
    int s;
    int e;
    int weight;
    MiniTreeEdge *next;
};

typedef struct MiniTree {
    MiniTreeEdge *head;
    int edgenumber;
};

typedef struct EdgeArrayData {
    int l;
    int r;
    int weight;
};

bool compare(EdgeArrayData a, EdgeArrayData b) {
    return a.weight < b.weight;
}

int find_parent(int node, int *parent) {
    while(parent[node] != node) {
        node = parent[node];
    }
    return node;
}

void  MiniSpanTree_Kruskal(GraphAdjList g, MiniTree *tree) {
    int i, j, k, edge_index, *parent;
    MiniTreeEdge *e;
    EdgeArrayData *edge = (EdgeArrayData*)malloc(sizeof(EdgeArrayData)*(g.edgenumber+2));
    parent = (int*)malloc(sizeof(int)*(g.vertexnumber+2));
    tree = (MiniTree*)malloc(sizeof(MiniTree));
    EdgeListNode *v;

	//将图中的每条边存储在edge里
    edge_index = 0;
    for(i=1; i<=g.vertexnumber; i++) {
        v = g.vertextlist[i].firstadj;
        parent[i] = i;
        while(v != NULL) {
            if(v->adjId > i) {  //为了避免将一条边存两次
                edge[edge_index].l = i;
                edge[edge_index].r = v->adjId;
                edge[edge_index].weight = v->weight;
                edge_index++;
            }
            v = v->next;
        }
    }
    sort(edge, edge+edge_index, compare); //将边按权重从小到大排序
    
    tree->edgenumber = 0;
    tree->head = NULL;
    for(i=0; i<edge_index; i++) {
        j = find_parent(edge[i].l, parent); 
        k = find_parent(edge[i].r, parent);
        if(j != k) {
            parent[j] = k;
            e = (MiniTreeEdge*)malloc(sizeof(MiniTreeEdge));
            e->s = edge[i].l;
            e->e = edge[i].r;
            e->weight = edge[i].weight;
            e->next = tree->head;
            tree->head = e;
            tree->edgenumber++;
        }
        if(tree->edgenumber == g.vertexnumber - 1) {
            break;
        }
    }

    MiniTreeEdge *ee = tree->head;
    while(ee != NULL) {
        cout<<ee->s<<" -> "<<ee->e<<"  :  "<<ee->weight<<endl;
        ee = ee->next;
    }
}

