/*Design the logic to remove the duplicate elements from an Array and after the 
deletion the array should contain the unique elements.*/

#include <iostream>
using namespace std;

int main()
{
    int arr[10], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: "<<endl;
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n;) 
        {
            if (arr[i] == arr[j])
            {
                //shifting elements to left
                for (int k = j; k < n - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                n--; 
            } 
            else
            {
                j++; 
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }

    return 0;
}

