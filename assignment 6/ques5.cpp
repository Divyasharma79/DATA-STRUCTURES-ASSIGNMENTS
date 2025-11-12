#include <bits/stdc++.h>
using namespace std;
struct Node{ int v; Node* next; Node(int x):v(x),next(nullptr){} };
int main(){
    int n; cin>>n;
    if(n==0){ cout<<"False\n"; return 0; }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int pos; cin>>pos;
    Node* head=new Node(a[0]);
    Node* t=head;
    vector<Node*> nodes; nodes.push_back(head);
    for(int i=1;i<n;i++){ t->next=new Node(a[i]); t=t->next; nodes.push_back(t); }
    if(pos==0) t->next=nullptr;
    else t->next = nodes[pos-1];
    bool isCircular=false;
    Node* slow=head; Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){ isCircular=true; break; }
    }
    cout<<(isCircular?"True\n":"False\n");
    return 0;
}
