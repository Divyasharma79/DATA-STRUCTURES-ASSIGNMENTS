#include <bits/stdc++.h>
using namespace std;
struct Node{ int val; Node* next; Node(int v):val(v),next(nullptr){} };
int main(){
    int n; cin>>n;
    if(n==0){ cout<<"\n"; return 0; }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    Node* head=new Node(a[0]);
    Node* t=head;
    for(int i=1;i<n;i++){ t->next=new Node(a[i]); t=t->next; }
    t->next=head;
    Node* cur=head;
    do{ cout<<cur->val<<" "; cur=cur->next; }while(cur!=head);
    cout<<head->val<<"\n";
    return 0;
}
