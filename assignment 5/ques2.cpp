#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void insertFront(Node*& head, int x) {
    Node* n = new Node;
    n->val = x;
    n->next = head;
    head = n;
}

int removeAll(Node*& head, int key) {
    int removed = 0;
    while (head && head->val == key) {
        Node* t = head;
        head = head->next;
        delete t;
        removed++;
    }
    Node* p = head;
    while (p && p->next) {
        if (p->next->val == key) {
            Node* del = p->next;
            p->next = del->next;
            delete del;
            removed++;
        } else {
            p = p->next;
        }
    }
    return removed;
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int i = 6; i >= 0; i--) {
        insertFront(head, arr[i]);
    }

    cout << "Before deletion: ";
    printList(head);

    int key = 1;
    int total = removeAll(head, key);

    cout << "Deleted " << total << " nodes with value " << key << endl;
    cout << "After deletion: ";
    printList(head);

    return 0;
}