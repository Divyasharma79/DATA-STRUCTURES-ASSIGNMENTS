#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int c=0;
    unordered_set<int> s;
    for(int x:a){
        if(s.count(x+k)) c++;
        if(s.count(x-k)) c++;
        s.insert(x);
    }
    cout << c;
}
