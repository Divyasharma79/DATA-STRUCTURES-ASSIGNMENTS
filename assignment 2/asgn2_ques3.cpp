/*
Design the Logic to Find a Missing Number in a Sorted Array. Given an array of 
n-1 distinct integers in the range of 1 to n, find the missing number in it in a Sorted 
Array 
(a) Linear time 
(b) Using binary search.
*/

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] - arr[i] > 1) return arr[i] + 1;
    }
    return n;  
}

int findMissingBinary(int arr[], int n) {
    int st = 0, ed = n-2;
    while (st <= ed) {
        int mid = st + (ed - st)/2;
        if (arr[mid] == mid+1) {
            st = mid + 1;
        } else {
            ed = mid - 1;
        }
    }
    return st + 1;
}

int main() {
    int arr[] = {1,2,3,5};
    int n = 5;

    cout << "Missing (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing (Binary): " << findMissingBinary(arr, n) << endl;

    return 0;
}