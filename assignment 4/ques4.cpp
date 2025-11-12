#include <bits/stdc++.h>
using namespace std;

void printFirstUnique(string s) {
    map<char,int> count;  
    queue<char> q;       

    for (char c : s) {
        
        count[c]++;
        q.push(c);

        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
}

int main() {
    string str = "aabc";
    printFirstUnique(str);
    return 0;
}