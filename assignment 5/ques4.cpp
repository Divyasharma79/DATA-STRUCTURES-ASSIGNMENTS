#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    for (int i = 4; i >= 1; i--) push(head, i); // 1->2->3->4
    cout << "Original: "; display(head);
    head = reverse(head);
    cout << "Reversed: "; display(head);
    return 0;
}