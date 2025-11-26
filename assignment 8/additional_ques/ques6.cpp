#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

Node* solve(vector<int>&in,vector<int>&post,int &i,int l,int r){
    if(l>r) return NULL;
    int val=post[i--];
    Node* root=new Node(val);
    int idx=find(in.begin(),in.end(),val)-in.begin();
    root->r=solve(in,post,i,idx+1,r);
    root->l=solve(in,post,i,l,idx-1);
    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->v<<" ";
    preorder(root->l);
    preorder(root->r);
}

int main(){
    int n;cin>>n;
    vector<int>in(n),post(n);
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>post[i];
    int i=n-1;
    Node* root=solve(in,post,i,0,n-1);
    preorder(root);
    cout<<"\n";
    return 0;
}
