#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node* next; Node* prev; Node* random;
    Node(int x):v(x),next(nullptr),prev(nullptr),random(nullptr){}
};
int main(){
    int n;cin>>n;
    vector<Node*> nodes;
    for(int i=0;i<n;i++) nodes.push_back(new Node(i+1));
    for(int i=0;i<n-1;i++){ nodes[i]->next=nodes[i+1]; nodes[i+1]->prev=nodes[i]; }
    int wrong;cin>>wrong;
    nodes[wrong-1]->random=nodes[(wrong+1)%n];
    nodes[wrong-1]->random=nodes[wrong-1]->next;
    for(auto x:nodes) cout<<x->v<<" ";
    cout<<"\n";
    return 0;
}
