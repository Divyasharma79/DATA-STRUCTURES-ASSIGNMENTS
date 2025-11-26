#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

Node* build(vector<int>&a){
    if(a.empty()) return NULL;
    Node* root=new Node(a[0]);
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<a.size()){
        Node* t=q.front(); q.pop();
        if(a[i]!=-1){
            t->l=new Node(a[i]);
            q.push(t->l);
        }
        i++;
        if(i<a.size() && a[i]!=-1){
            t->r=new Node(a[i]);
            q.push(t->r);
        }
        i++;
    }
    return root;
}

int depth(Node* root){
    if(!root) return 0;
    return 1+max(depth(root->l),depth(root->r));
}

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        Node* root=build(a);
        cout<<depth(root)<<"\n";
    }
    return 0;
}
