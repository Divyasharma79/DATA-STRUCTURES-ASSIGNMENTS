#include<iostream>
#include<stack>
using namespace std;

void reverseString(string str){
    stack<char> c;
    for(char a : str){
        c.push(a);
    }
    
    cout<<"Reversed String: ";
    while(!c.empty()){
        cout<<c.top();
        c.pop();
    }
    cout<<endl;
}
int main(){
    string str = "DataStructure";
    cout<<"Original: "<<str<<endl;
    reverseString(str);
    
    return 0;
}