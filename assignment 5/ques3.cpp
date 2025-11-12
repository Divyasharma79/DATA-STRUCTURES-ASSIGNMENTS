#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void insert(Node*& head, int x) {
    Node* n = new Node{x, head};
    head = n;
}

int getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->val;
}

int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; i--) insert(head, i);
    cout << "Middle: " << getMiddle(head) << endl;
    return 0;
}