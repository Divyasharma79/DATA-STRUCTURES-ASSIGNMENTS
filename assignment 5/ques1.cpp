#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList {
    Node* start;

public:
    LinkedList() { start = NULL; }

    void insertFront(int x) {
        Node* n = new Node;
        n->val = x;
        n->next = start;
        start = n;
    }

    void insertBack(int x) {
        Node* n = new Node{ x, NULL };
        if (start == NULL) {
            start = n;
            return;
        }
        Node* p = start;
        while (p->next) p = p->next;
        p->next = n;
    }

    
    void insertBefore(int key, int x) {
        if (!start) return;
        if (start->val == key) { insertFront(x); return; }
        Node* p = start;
        while (p->next && p->next->val != key) p = p->next;
        if (p->next) {
            Node* n = new Node{ x, p->next };
            p->next = n;
        }
    }

    
    void insertAfter(int key, int x) {
        Node* p = start;
        while (p && p->val != key) p = p->next;
        if (p) {
            Node* n = new Node{ x, p->next };
            p->next = n;
        }
    }


    void deleteFront() {
        if (!start) return;
        Node* t = start;
        start = start->next;
        delete t;
    }

    
    void deleteBack() {
        if (!start) return;
        if (!start->next) { delete start; start = NULL; return; }
        Node* p = start;
        while (p->next->next) p = p->next;
        delete p->next;
        p->next = NULL;
    }

    
    void deleteKey(int key) {
        if (!start) return;
        if (start->val == key) { deleteFront(); return; }
        Node* p = start;
        while (p->next && p->next->val != key) p = p->next;
        if (p->next) {
            Node* del = p->next;
            p->next = del->next;
            delete del;
        }
    }

    
    void find(int key) {
        Node* p = start;
        int pos = 1;
        while (p) {
            if (p->val == key) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            p = p->next; pos++;
        }
        cout << "Element not found\n";
    }


    void show() {
        cout << "Linked List: ";
        Node* p = start;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList L;
    int ch, val, key;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1.Insert Front\n2.Insert End\n3.Insert Before\n4.Insert After\n";
        cout << "5.Delete Front\n6.Delete End\n7.Delete Key\n";
        cout << "8.Search\n9.Display\n10.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Value: "; cin >> val; L.insertFront(val); break;
            case 2: cout << "Value: "; cin >> val; L.insertBack(val); break;
            case 3: cout << "Key and Value: "; cin >> key >> val; L.insertBefore(key, val); break;
            case 4: cout << "Key and Value: "; cin >> key >> val; L.insertAfter(key, val); break;
            case 5: L.deleteFront(); break;
            case 6: L.deleteBack(); break;
            case 7: cout << "Key: "; cin >> key; L.deleteKey(key); break;
            case 8: cout << "Key: "; cin >> key; L.find(key); break;
            case 9: L.show(); break;
        }
    } while (ch != 10);

    return 0;
}