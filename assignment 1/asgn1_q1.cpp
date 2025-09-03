#include <iostream>
using namespace std;

void createArray(int arr[], int &n)
{
    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter elements in array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n)
{
    cout << "Entered array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n)
{
    int element, position;
    cout << "Enter the position where you want to add the element: ";
    cin >> position;
    cout << "Enter the element you want to add: ";
    cin >> element;

    if (position < 1 || position > n + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    n++;
}

void deleteElement(int arr[], int &n)
{
    int position;
    cout << "Enter the position of the element you want to delete: ";
    cin >> position;

    if (position < 1 || position > n)
    {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = position - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearSearch(int arr[], int n)
{
    int element;
    cout << "Enter the element you want to search: ";
    cin >> element;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            cout << "Element found at position: " << i + 1 << endl;
            return;
        }
    }
    cout << "Error 404 - Element not found" << endl;
}

int main()
{
    int arr[100];
    int n = 0;
    int arrCreated = 0;
    int selectOp = 0;

    while (selectOp != 6)
    {
        cout << "\nChoose:\n";
        cout << "1. Create array\n";
        cout << "2. Display array\n";
        cout << "3. Insert element\n";
        cout << "4. Delete element\n";
        cout << "5. Search element\n";
        cout << "6. Exit\n";
        cin >> selectOp;

        switch (selectOp)
        {
        case 1:
            if (arrCreated == 0)
            {
                createArray(arr, n);
                arrCreated = 1;
            }
            else
            {
                cout << "Array already created." << endl;
                displayArray(arr, n);
            }
            break;

        case 2:
            if (arrCreated == 0)
                cout << "Please create an array first." << endl;
            else
                displayArray(arr, n);
            break;

        case 3:
            if (arrCreated == 0)
                cout << "Array not created." << endl;
            else if (n == 100)
                cout << "No space in array. Try deleting an element first." << endl;
            else
                insertElement(arr, n);
            break;

        case 4:
            if (arrCreated == 0)
                cout << "Array not created." << endl;
            else
                deleteElement(arr, n);
            break;

        case 5:
            if (arrCreated == 0)
                cout << "Array not created." << endl;
            else
                linearSearch(arr, n);
            break;
        }
    }
    return 0;
}
