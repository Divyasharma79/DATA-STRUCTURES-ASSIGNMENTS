#include <bits/stdc++.h>
using namespace std;

struct DNode{
    int val;
    DNode *prev,*next;
    DNode(int v):val(v),prev(nullptr),next(nullptr){}
};

struct CNode{
    int val;
    CNode *next;
    CNode(int v):val(v),next(nullptr){}
};

struct Doubly{
    DNode* head=nullptr;
    void insertFirst(int x){
        DNode* p=new DNode(x);
        if(!head) head=p;
        else{ p->next=head; head->prev=p; head=p; }
    }
    void insertLast(int x){
        DNode* p=new DNode(x);
        if(!head) head=p;
        else{
            DNode* t=head;
            while(t->next) t=t->next;
            t->next=p; p->prev=t;
        }
    }
    void insertAfter(int key,int x){
        DNode* t=head;
        while(t && t->val!=key) t=t->next;
        if(!t) return;
        DNode* p=new DNode(x);
        p->next=t->next;
        p->prev=t;
        if(t->next) t->next->prev=p;
        t->next=p;
    }
    void insertBefore(int key,int x){
        DNode* t=head;
        while(t && t->val!=key) t=t->next;
        if(!t) return;
        DNode* p=new DNode(x);
        p->next=t;
        p->prev=t->prev;
        if(t->prev) t->prev->next=p;
        else head=p;
        t->prev=p;
    }
    void deleteNode(int key){
        DNode* t=head;
        while(t && t->val!=key) t=t->next;
        if(!t) return;
        if(t->prev) t->prev->next=t->next;
        else head=t->next;
        if(t->next) t->next->prev=t->prev;
        delete t;
    }
    bool search(int key){
        DNode* t=head;
        while(t){ if(t->val==key) return true; t=t->next; }
        return false;
    }
    void display(){
        DNode* t=head;
        while(t){ cout<<t->val<<" "; t=t->next; }
        cout<<"\n";
    }
};

struct Circular{
    CNode* head=nullptr;
    void insertFirst(int x){
        CNode* p=new CNode(x);
        if(!head){ head=p; p->next=head; return; }
        CNode* t=head;
        while(t->next!=head) t=t->next;
        p->next=head;
        t->next=p;
        head=p;
    }
    void insertLast(int x){
        CNode* p=new CNode(x);
        if(!head){ head=p; p->next=head; return; }
        CNode* t=head;
        while(t->next!=head) t=t->next;
        t->next=p; p->next=head;
    }
    void insertAfter(int key,int x){
        if(!head) return;
        CNode* t=head;
        do{
            if(t->val==key){
                CNode* p=new CNode(x);
                p->next=t->next;
                t->next=p;
                return;
            }
            t=t->next;
        }while(t!=head);
    }
    void insertBefore(int key,int x){
        if(!head) return;
        if(head->val==key){ insertFirst(x); return; }
        CNode* t=head;
        while(t->next!=head && t->next->val!=key) t=t->next;
        if(t->next->val==key){
            CNode* p=new CNode(x);
            p->next=t->next;
            t->next=p;
        }
    }
    void deleteNode(int key){
        if(!head) return;
        if(head->val==key){
            if(head->next==head){ delete head; head=nullptr; return; }
            CNode* t=head;
            while(t->next!=head) t=t->next;
            CNode* toDel=head;
            head=head->next;
            t->next=head;
            delete toDel;
            return;
        }
        CNode* t=head;
        while(t->next!=head && t->next->val!=key) t=t->next;
        if(t->next->val==key){
            CNode* toDel=t->next;
            t->next=toDel->next;
            delete toDel;
        }
    }
    bool search(int key){
        if(!head) return false;
        CNode* t=head;
        do{ if(t->val==key) return true; t=t->next;}while(t!=head);
        return false;
    }
    void displayRepeatHead(){
        if(!head) { cout<<"\n"; return; }
        CNode* t=head;
        do{ cout<<t->val<<" "; t=t->next; }while(t!=head);
        cout<<head->val<<"\n";
    }
    void display(){
        if(!head){ cout<<"\n"; return; }
        CNode* t=head;
        do{ cout<<t->val<<" "; t=t->next; }while(t!=head);
        cout<<"\n";
    }
};

int main(){
    Doubly dl;
    Circular cl;
    while(true){
        cout<<"Choose list: 1-Doubly 2-Circular 0-Exit\n";
        int L; if(!(cin>>L)) return 0;
        if(L==0) break;
        if(L==1){
            cout<<"1-insertFirst 2-insertLast 3-insertAfter 4-insertBefore 5-delete 6-search 7-display\n";
            int op; cin>>op;
            if(op==1){ int x; cin>>x; dl.insertFirst(x); }
            else if(op==2){ int x; cin>>x; dl.insertLast(x); }
            else if(op==3){ int k,x; cin>>k>>x; dl.insertAfter(k,x); }
            else if(op==4){ int k,x; cin>>k>>x; dl.insertBefore(k,x); }
            else if(op==5){ int k; cin>>k; dl.deleteNode(k); }
            else if(op==6){ int k; cin>>k; cout<<(dl.search(k)?"True\n":"False\n"); }
            else if(op==7) dl.display();
        }else{
            cout<<"1-insertFirst 2-insertLast 3-insertAfter 4-insertBefore 5-delete 6-search 7-display 8-displayRepeatHead\n";
            int op; cin>>op;
            if(op==1){ int x; cin>>x; cl.insertFirst(x); }
            else if(op==2){ int x; cin>>x; cl.insertLast(x); }
            else if(op==3){ int k,x; cin>>k>>x; cl.insertAfter(k,x); }
            else if(op==4){ int k,x; cin>>k>>x; cl.insertBefore(k,x); }
            else if(op==5){ int k; cin>>k; cl.deleteNode(k); }
            else if(op==6){ int k; cin>>k; cout<<(cl.search(k)?"True\n":"False\n"); }
            else if(op==7) cl.display();
            else if(op==8) cl.displayRepeatHead();
        }
    }
    return 0;
}
