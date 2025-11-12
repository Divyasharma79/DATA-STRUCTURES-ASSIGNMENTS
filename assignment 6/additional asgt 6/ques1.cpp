#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node* next;
    Node(int x):v(x),next(nullptr){}
};
void split(Node* head, Node** head1, Node** head2){
    if(!head) return;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1=head;
    if(head->next!=head) *head2=slow->next;
    if(fast->next->next==head) fast=fast->next;
    fast->next=*head2;
    slow->next=*head1;
}
int main(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    Node* head=new Node(a[0]);
    Node* t=head;
    for(int i=1;i<n;i++){ t->next=new Node(a[i]); t=t->next; }
    t->next=head;
    Node *h1=nullptr,*h2=nullptr;
    split(head,&h1,&h2);
    Node* p=h1;
    do{ cout<<p->v<<" "; p=p->next; }while(p!=h1);
    cout<<"\n";
    p=h2;
    do{ cout<<p->v<<" "; p=p->next; }while(p!=h2);
    cout<<"\n";
    return 0;
}
