#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> students(n), sandwiches(n);
    for(int i=0;i<n;i++) cin>>students[i];
    for(int i=0;i<n;i++) cin>>sandwiches[i];
    queue<int> q;
    for(int x:students) q.push(x);
    int i=0,cnt=0;
    while(!q.empty() && cnt<q.size()){
        if(q.front()==sandwiches[i]){
            q.pop();
            i++;
            cnt=0;
        }else{
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }
    cout<<q.size();
}
