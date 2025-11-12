#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt=0;
    for(int x:a) if(x==2) cnt++;
    for(int i=n-1;i>=0;i--){
        int j = i + cnt;
        if(j < n) a[j] = a[i];
        if(a[i]==2){
            cnt--;
            if(i+cnt < n) a[i+cnt] = 2;
        }
    }
    for(int x:a) cout << x << " ";
}
