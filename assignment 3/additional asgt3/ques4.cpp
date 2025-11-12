#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> t(n), ans(n,0);
    for(int i=0;i<n;i++) cin >> t[i];
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && t[i]>t[st.top()]){
            int j=st.top();st.pop();
            ans[j]=i-j;
        }
        st.push(i);
    }
    for(int x:ans) cout << x << " ";
}
