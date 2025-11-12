#include <bits/stdc++.h>
using namespace std;
struct Node{ char c; Node* prev; Node* next; Node(char x):c(x),prev(nullptr),next(nullptr){} };
int main(){
    int n; cin>>n;
    if(n==0){ cout<<"True\n"; return 0; }
    Node* head=nullptr; Node* tail=nullptr;
    for(int i=0;i<n;i++){
        char ch; cin>>ch;
        Node* p=new Node(ch);
        if(!head) head=tail=p;
        else{ tail->next=p; p->prev=tail; tail=p; }
    }
    Node* l=head; Node* r=tail;
    bool ok=true;
    while(l && r && l!=r && l->prev!=r){
        if(l->c!=r->c){ ok=false; break; }
        l=l->next; r=r->prev;
    }
    cout<<(ok?"True\n":"False\n");
    return 0;
}
