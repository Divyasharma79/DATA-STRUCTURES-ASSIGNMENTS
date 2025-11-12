#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node* next; Node* prev;
    Node(int x):v(x),next(nullptr),prev(nullptr){}
};
Node* reverseK(Node* head,int k){
    Node* curr=head,*next=nullptr,*prev=nullptr;
    int c=0;
    while(curr && c<k){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
        c++;
    }
    if(next) head->next=reverseK(next,k);
    if(head->next) head->next->prev=head;
    return prev;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    Node* h=new Node(a[0]),*t=h;
    for(int i=1;i<n;i++){ t->next=new Node(a[i]); t->next->prev=t; t=t->next; }
    h=reverseK(h,k);
    for(Node* x=h;x;x=x->next) cout<<x->v<<" ";
    cout<<"\n";
    return 0;
}
