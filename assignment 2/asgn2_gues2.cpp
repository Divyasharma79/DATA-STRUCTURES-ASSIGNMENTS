/*Bubble Sort is the simplest sorting algorithm that works by repeatedly 
swapping the adjacent elements if they are in the wrong order. Code the Bubble sort 
with the following elements: 
64 34 25 12 22 11 90*/
#include <iostream>
using namespace std;

void steps(int arr[], int n, int j) {
    if (j == n - 1) {
        return;
    }

    if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
    }

    steps(arr, n, j + 1);
}

void bubbleSort(int arr[], int n) {
    if (n == 1) {
        return;
    }

    steps(arr, n, 0);
    bubbleSort(arr, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}