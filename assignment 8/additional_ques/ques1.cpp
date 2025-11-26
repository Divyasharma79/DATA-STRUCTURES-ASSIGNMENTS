#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

Node* build(vector<int> &a,int i){
    if(i>=a.size() || a[i]==-1) return NULL;
    Node* root=new Node(a[i]);
    root->l=build(a,2*i+1);
    root->r=build(a,2*i+2);
    return root;
}

int sumLeft(Node* root,bool isLeft){
    if(!root) return 0;
    if(!root->l && !root->r && isLeft) return root->v;
    return sumLeft(root->l,true)+sumLeft(root->r,false);
}

int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Node* root=build(a,0);
    cout<<sumLeft(root,false)<<"\n";
    return 0;
}
