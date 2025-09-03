/*Write a program to find sum of every row and every column in a two-dimensional 
array.*/
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    int arr[m][n];
    cout << "Enter elements of the matrix:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "Sum of each row:\n";
    for(int i = 0; i < m; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum = sum + arr[i][j];
        }
        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }

    cout << "Sum of each column:\n";
    for(int j = 0; j < n; j++) {
        int sum = 0;
        for(int i = 0; i < m; i++) {
            sum += arr[i][j];
        }
        cout << "Sum of column" << j + 1 << " = " << sum << endl;
    }

    return 0;
}