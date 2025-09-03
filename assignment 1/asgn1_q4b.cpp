//b. Find the matrix multiplication
#include <iostream>
using namespace std;

int main() {
    int row1, col1, col2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> row1 >> col1;

    int A[row1][col1];
    cout << "Enter elements of first matrix:\n";
    for(int i = 0; i < row1; i++)
        for(int j = 0; j < col1; j++)
            cin >> A[i][j];

    cout << "Enter columns of second matrix: ";
    cin >> col2;

    int B[col1][col2];
    cout << "Enter elements of second matrix:\n";
    for(int i = 0; i < col1; i++)
        for(int j = 0; j < col2; j++)
            cin >> B[i][j];

    int C[row1][col2] = {0}; 

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}