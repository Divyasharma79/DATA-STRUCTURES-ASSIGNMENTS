#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

vector<Node*> solve(int s,int e){
    if(s>e) return {NULL};
    vector<Node*> ans;
    for(int i=s;i<=e;i++){
        auto L=solve(s,i-1);
        auto R=solve(i+1,e);
        for(auto l:L){
            for(auto r:R){
                Node* root=new Node(i);
                root->l=l;
                root->r=r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

void preorder(Node* root){
    if(!root){ cout<<"null "; return; }
    cout<<root->v<<" ";
    preorder(root->l);
    preorder(root->r);
}

int main(){
    int n;cin>>n;
    auto res=solve(1,n);
    for(auto t:res){
        preorder(t);
        cout<<"\n";
    }
    return 0;
}
