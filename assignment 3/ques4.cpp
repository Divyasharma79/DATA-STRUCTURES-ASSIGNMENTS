#include <iostream>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (char c : exp) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop(); 
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
  while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    string exp;
    cout<<"Enter expression: ";
    cin>>exp;
    cout << "Postfix: " << infixToPostfix(exp) << endl;
}