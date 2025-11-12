#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b;
    stack<int> s;
    int want=1;
    for(int i=0;i<n;i++){
        s.push(a[i]);
        while(!s.empty() && s.top()==want){
            b.push_back(s.top());
            s.pop();
            want++;
        }
    }
    cout<<(b.size()==n ? "YES" : "NO");
}
