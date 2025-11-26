#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=NULL;}
};

Node* insertBST(Node* root,int x){
    if(!root) return new Node(x);
    if(x<root->v) root->l=insertBST(root,x);
    else if(x>root->v) root->r=insertBST(root,x);
    return root;
}

void inorder(Node* root,vector<int> &v){
    if(!root) return;
    inorder(root->l,v);
    v.push_back(root->v);
    inorder(root->r,v);
}

struct D{
    int v; D *prev,*next;
    D(int x){v=x;prev=next=NULL;}
};

int main(){
    int n1;cin>>n1;
    Node* t1=NULL;
    for(int i=0;i<n1;i++){
        int x;cin>>x;
        t1=insertBST(t1,x);
    }
    int n2;cin>>n2;
    Node* t2=NULL;
    for(int i=0;i<n2;i++){
        int x;cin>>x;
        t2=insertBST(t2,x);
    }
    vector<int>a,b;
    inorder(t1,a);
    inorder(t2,b);

    vector<int> m;
    merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(m));

    D* head=new D(m[0]);
    D* t=head;
    for(int i=1;i<m.size();i++){
        t->next=new D(m[i]);
        t->next->prev=t;
        t=t->next;
    }

    D* p=head;
    while(p){
        cout<<p->v<<" ";
        p=p->next;
    }

    cout<<"\n";
    return 0;
}
