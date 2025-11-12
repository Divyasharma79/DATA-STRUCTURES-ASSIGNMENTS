#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), ans;
    for(int i=0;i<n;i++) cin >> a[i];
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=a[i]) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(a[i]);
    }
    for(int x:ans) cout << x << " ";
}
