#include<bits/stdc++.h>

using namespace std;
const int N = 50010;
int n;
struct Node {
	int s, w;
}node[N];

bool cmp(Node a, Node b) {
	return a.s + a.w < b.s + b.w;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &node[i].w, &node[i].s);
	}
	sort(node, node + n, cmp);
	int sum = 0, res = -29;
	for (int i = 0; i < n; ++i) {
		res = max(res, sum - node[i].s);
		sum += node[i].w;
	}

	printf("%lld\n", res);

	return 0;
}
