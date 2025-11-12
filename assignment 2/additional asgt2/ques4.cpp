#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int l=0,m=0,h=n-1;
    while(m<=h){
        if(a[m]==0) swap(a[l++],a[m++]);
        else if(a[m]==1) m++;
        else swap(a[m],a[h--]);
    }
    for(int x:a) cout << x << " ";
}
