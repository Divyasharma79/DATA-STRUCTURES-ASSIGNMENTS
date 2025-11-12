#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node *right,*down,*left,*up;
    Node(int x):v(x),right(nullptr),down(nullptr),left(nullptr),up(nullptr){}
};
int main(){
    int r,c;cin>>r>>c;
    vector<vector<int>> a(r,vector<int>(c));
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>a[i][j];
    vector<vector<Node*>> mat(r,vector<Node*>(c,nullptr));
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) mat[i][j]=new Node(a[i][j]);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j+1<c){ mat[i][j]->right=mat[i][j+1]; mat[i][j+1]->left=mat[i][j]; }
            if(i+1<r){ mat[i][j]->down=mat[i+1][j]; mat[i+1][j]->up=mat[i][j]; }
        }
    }
    Node* head=mat[0][0];
    Node* row=head;
    while(row){
        Node* cur=row;
        while(cur){ cout<<cur->v<<" "; cur=cur->right; }
        cout<<"\n";
        row=row->down;
    }
    return 0;
}
