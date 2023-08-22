#include <iostream>
using namespace std;
struct LinkNode{
    int val;
    LinkNode* next;
};

int main(){
    LinkNode x1;
    x1.val = 1;
    LinkNode x2;
    x1.next = x2;
    x2.val = 5;
    cout<<x1.next.val;
    return 0;
}
