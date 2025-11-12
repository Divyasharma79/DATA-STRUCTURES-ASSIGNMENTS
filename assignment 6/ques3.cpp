#include <bits/stdc++.h>
using namespace std;
struct DNode{ int v; DNode* prev; DNode* next; DNode(int x):v(x),prev(nullptr),next(nullptr){} };
struct CNode{ int v; CNode* next; CNode(int x):v(x),next(nullptr){} };
int main(){
    int n1; cin>>n1;
    DNode* dh=nullptr;
    DNode* dt=nullptr;
    for(int i=0;i<n1;i++){
        int x; cin>>x;
        DNode* p=new DNode(x);
        if(!dh) dh=dt=p;
        else{ dt->next=p; p->prev=dt; dt=p;}
    }
    int n2; cin>>n2;
    CNode* ch=nullptr;
    CNode* ct=nullptr;
    for(int i=0;i<n2;i++){
        int x; cin>>x;
        CNode* p=new CNode(x);
        if(!ch) ch=ct=p;
        else{ ct->next=p; ct=p; }
    }
    if(ct) ct->next=ch;
    int sizeD=0;
    for(DNode* t=dh;t;t=t->next) sizeD++;
    int sizeC=0;
    if(ch){
        CNode* t=ch;
        do{ sizeC++; t=t->next; }while(t!=ch);
    }
    cout<<sizeD<<" "<<sizeC<<"\n";
    return 0;
}
