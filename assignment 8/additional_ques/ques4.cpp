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

vector<int> rightView(Node* root){
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            Node* t=q.front(); q.pop();
            if(i==s-1) ans.push_back(t->v);
            if(t->l) q.push(t->l);
            if(t->r) q.push(t->r);
        }
    }
    return ans;
}

int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        Node* root=build(a);
        auto v=rightView(root);
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}
