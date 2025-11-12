#include <iostream>
using namespace std;

#define MAX 50
int stackArr[MAX];
int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == MAX - 1;
    
}

void push(int x){
    if(isFull()){
        cout<<"Error: Array already full"<<endl;
}
else{
    top++;
    stackArr[top] = x;
    cout<<x<<" is pushed into stack"<<endl;
}
}

void pop(){
    if(isEmpty()){
        cout<<"Error: Array is empty"<<endl;
    }
    else{
        cout<<"current top element: "<<stackArr[top]<<endl;
        top--;
    }
}

void peek(){
    if(isEmpty()){
        cout<<"Error: No element in array"<<endl;
    }
    else{
        cout<<"top element: "<<stackArr[top]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"Stack is empty."<<endl;
    }
    else{
        cout<<"Stack Elements: "<<endl;
        for(int i = top; i>=0; i--){
            cout<<stackArr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
   int access, value;
   do{
       cout<<"\n --- Stack Menu ---\n";
       cout<<"1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Exit\n";
       cout<<"Enter the function you want to execute";
       cin>>access;
       switch(access){
           case 1: {
               cout<<"Enter value: ";
               cin>>value;
               push(value);
               break;
           }
           case 2: pop(); break;
           case 3: peek(); break;
           case 4: display(); break;
           case 5: cout<<"Exiting...\n"; break;
           default: cout<<"Invalid choice \n";
       }
   } while(access !=5);
    return 0;
}