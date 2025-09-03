/*
 Write a program to count the total number of distinct elements in an array of 
length n.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> st;
    for (int i = 0; i < n; i++) st.insert(arr[i]);

    cout << "Total distinct elements: " << st.size() << endl;

    return 0;
}