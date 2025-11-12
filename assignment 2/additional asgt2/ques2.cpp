#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool ok = false;
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            string a = s.substr(0,i);
            string b = s.substr(i,j-i);
            string c = s.substr(j);
            if((a.find(b)!=string::npos && c.find(b)!=string::npos) ||
               (b.find(a)!=string::npos && c.find(a)!=string::npos) ||
               (a.find(c)!=string::npos && b.find(c)!=string::npos)){
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << (ok ? "YES" : "NO");
}
