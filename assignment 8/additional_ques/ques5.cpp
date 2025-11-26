#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

Node* solve(vector<int>&pre,vector<int>&in,int &i,int l,int r){
    if(l>r) return NULL;
    int val=pre[i++];
    Node* root=new Node(val);
    int idx=find(in.begin(),in.end(),val)-in.begin();
    root->l=solve(pre,in,i,l,idx-1);
    root->r=solve(pre,in,i,idx+1,r);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->l);
    cout<<root->v<<" ";
    inorder(root->r);
}

int main(){
    int n;cin>>n;
    vector<int>pre(n),in(n);
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];
    int idx=0;
    Node* root=solve(pre,in,idx,0,n-1);
    inorder(root);
    cout<<"\n";
    return 0;
}
