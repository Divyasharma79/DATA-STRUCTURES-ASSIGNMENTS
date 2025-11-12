#include <bits/stdc++.h>
using namespace std;
int getMinIndex(queue<int>&q,int sortedIndex){
    int minIndex=-1,minVal=INT_MAX;
    int n=q.size();
    for(int i=0;i<n;i++){
        int curr=q.front();q.pop();
        if(curr<=minVal && i<=sortedIndex){
            minIndex=i;
            minVal=curr;
        }
        q.push(curr);
    }
    return minIndex;
}
void insertMinToRear(queue<int>&q,int minIndex){
    int minVal;
    int n=q.size();
    for(int i=0;i<n;i++){
        int curr=q.front();q.pop();
        if(i!=minIndex) q.push(curr);
        else minVal=curr;
    }
    q.push(minVal);
}
int main(){
    int n;cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){int x;cin>>x;q.push(x);}
    for(int i=1;i<=n;i++){
        int minIndex=getMinIndex(q,n-i);
        insertMinToRear(q,minIndex);
    }
    while(!q.empty()){cout<<q.front()<<" ";q.pop();}
}
