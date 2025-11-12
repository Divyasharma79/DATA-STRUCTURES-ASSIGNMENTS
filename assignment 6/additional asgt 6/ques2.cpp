#include <bits/stdc++.h>
using namespace std;
int parity(int n){ int c=0; while(n){ if(n&1)c++; n>>=1; } return c; }
struct DNode{
    int v; DNode* prev; DNode* next;
    DNode(int x):v(x),prev(nullptr),next(nullptr){}
};
struct CNode{
    int v; CNode* next;
    CNode(int x):v(x),next(nullptr){}
};
int main(){
    int n1;cin>>n1;
    vector<int>a(n1);
    for(int i=0;i<n1;i++)cin>>a[i];
    DNode* dh=nullptr; DNode* dt=nullptr;
    for(int x:a){
        DNode* p=new DNode(x);
        if(!dh) dh=dt=p;
        else{ dt->next=p; p->prev=dt; dt=p; }
    }
    DNode* t=dh;
    while(t){
        int p=parity(t->v);
        DNode* nxt=t->next;
        if(p%2==0){
            if(t->prev) t->prev->next=t->next;
            else dh=t->next;
            if(t->next) t->next->prev=t->prev;
            delete t;
        }
        t=nxt;
    }
    for(DNode* x=dh;x;x=x->next) cout<<x->v<<" ";
    cout<<"\n";
    int n2;cin>>n2;
    vector<int>b(n2);
    for(int i=0;i<n2;i++)cin>>b[i];
    CNode* ch=nullptr; CNode* ct=nullptr;
    for(int x:b){
        CNode* p=new CNode(x);
        if(!ch) ch=ct=p;
        else{ ct->next=p; ct=p; }
    }
    if(ct) ct->next=ch;
    CNode* prev=ct; CNode* cur=ch;
    do{
        int p=parity(cur->v);
        if(p%2==0){
            if(cur==ch){
                if(ch->next==ch){ delete ch; ch=nullptr; break; }
                ch=ch->next; ct->next=ch; delete cur; cur=ch; prev=ct;
            }else{
                prev->next=cur->next; delete cur; cur=prev->next;
            }
        }else{ prev=cur; cur=cur->next; }
    }while(ch && cur!=ch);
    if(ch){
        CNode* p=ch;
        do{ cout<<p->v<<" "; p=p->next; }while(p!=ch);
    }
    cout<<"\n";
    return 0;
}
