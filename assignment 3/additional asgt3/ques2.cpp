#include <bits/stdc++.h>
using namespace std;
class MyStack{
    stack<long long> s;
    long long mn;
public:
    void push(long long x){
        if(s.empty()){
            s.push(x);
            mn=x;
        }else if(x<mn){
            s.push(2*x-mn);
            mn=x;
        }else s.push(x);
    }
    void pop(){
        if(s.empty()) return;
        long long t=s.top();
        s.pop();
        if(t<mn) mn=2*mn-t;
    }
    long long top(){
        long long t=s.top();
        if(t<mn) return mn;
        return t;
    }
    long long getMin(){return mn;}
};
int main(){
    MyStack st;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        st.push(x);
    }
    cout<<st.getMin();
}
