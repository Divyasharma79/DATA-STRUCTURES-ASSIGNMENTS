/*Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an 
inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to 
count the number of inversions in an array. */

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
   int merge(vector<int>& arr,int l,int mid,int r){
        
        vector<int> temp;
        int left = l; 
        int right = mid+1;
        int count = 0;
        while(left<=mid && right <=r){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            
            else{
                temp.push_back(arr[right]);
                count += (mid-left + 1);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = l; i <= r ;i++){
            arr[i] = temp[i-l];
        }
        
        return count;
    }
    int mergeSort(vector<int>& arr, int l, int r) {

        int count = 0;
        if(l==r) return count;
        int mid = (l+r)/2;
        count += mergeSort(arr,l,mid);
        count += mergeSort(arr,mid+1,r);
        count += merge(arr,l,mid,r);
        return count;
    }
    int inversionCount(vector<int> &arr) {
         return mergeSort(arr,0,arr.size()-1);
        
        
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;
    int invCount = sol.inversionCount(arr);
    cout << "Inversion count: " << invCount << endl;
    return 0;
}
