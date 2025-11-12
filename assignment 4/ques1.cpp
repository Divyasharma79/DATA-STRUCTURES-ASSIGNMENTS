#include<bits/stdc++.h>
using namespace std;

# define size 5

class Queue{

  int arr[size];
  int front;
  int rear;
  
  public:
  Queue(){
      front = -1;
      rear = -1;
  }
  
  //check if empty
  bool isEmpty(){
      return (front == -1 && rear == -1);
  }
  
  bool isFull(){
      return (rear == size-1);
  }
  
  void enqueue(int x){
      if(isFull()){
          cout<<"Array already full."<<endl;
          return;
      }
      
      if(isEmpty()){
          front = 0 ;
          rear = 0;
      }
      else{
          rear++;
      }
      arr[rear] = x;
      cout<<"element "<<x<<" is added to the queue."<<endl;
  }
  
  void dequeue(){
      if(isEmpty()){
          cout<<"Array already empty."<<endl;
      }
      cout<<arr[front]<< " removed from the queue."<<endl;
      
      if(front == rear) // means only 1 element is there 
      {
          front = rear = -1;
      }
      else{
          front++;
      }
  }
  
  void peek(){
      if(isEmpty()){
          cout<<"No element to peek.\n";
      }
      else{
          cout<<"Front element "<<arr[front]<<endl;
      }
  }
  
  void display(){
      if(isEmpty()){
          cout<<"Queue is empty.\n";
      }
      else{
          cout<<"Queue: "<<endl;
          for(int i = front; i<=rear; i++){
              cout<<arr[i]<<" ";
          }
      }
      cout<<endl;
  }
};
  
  int main(){
      Queue q;
      int choice, value;
      
      do {
        cout << "\n--- MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
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
    } while (choice != 0);

    return 0;
}
  
  
  
  
  
  
  