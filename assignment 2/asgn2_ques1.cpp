//Implement the binary search algorithm regarded as a fast search algorithm 
//with run-time complexity of Ο(log n) in comparison to the Linear Search. 
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int key;
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nEnter element to search: ";
    cin >> key;

    int left = 0, right = arr.size() - 1, found = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            found = mid;
            break;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (found != -1)
        cout << "Element found at index " << found << endl;
    else
        cout << "Element not found\n";
}