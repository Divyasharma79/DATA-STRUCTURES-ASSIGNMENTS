#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){int x;cin>>x;q.push(x);}
    stack<int> s;
    int expected=1;
    while(!q.empty()){
        int f=q.front();q.pop();
        if(f==expected) expected++;
        else{
            if(!s.empty() && s.top()<f){
                cout<<"No";
                return 0;
            }
            s.push(f);
        }
        while(!s.empty() && s.top()==expected){
            s.pop();
            expected++;
        }
    }
    cout<<(expected-1==n ? "Yes" : "No");
}
