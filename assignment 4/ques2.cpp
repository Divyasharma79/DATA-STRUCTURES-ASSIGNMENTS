#include<bits/stdc++.h>
using namespace std;

#define size 5

class CircularQueue{
    
    int arr[size];
    int front , rear;
    
    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }
    
    bool isEmpty(){
        return (front == -1);
    }
    
    bool isFull(){
        return ((rear+1)%size == front);
    }
    
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue  is full.\n";
            return;
        }
        
        if (isEmpty()) {  
            front = rear = 0;
        } else {
            rear = (rear + 1) % size; 
        }
        arr[rear] = x;
        cout << x << " added to queue\n";
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << arr[front] << " removed from queue\n";

        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % size;  
        }
    }
        
    void peek() {
        if (isEmpty())
            cout << "Queue is EMPTY\n";
        else
            cout << "Front element = " << arr[front] << "\n";
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};
    
    int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front)\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
                break;
            case 6:
                cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT full\n");
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}