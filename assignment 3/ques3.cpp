#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.top(); s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string str;
    cout<<"Enter the expression that contains parantheses"<<endl;
    cin>>str;
    if (isBalanced(str))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}