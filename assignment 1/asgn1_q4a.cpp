/*Implement the logic to 
a. Reverse the elements of an array 
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements of the array:"<<endl;
    cin>>n;
    
    cout<<"Enter the elements of array:"<<endl;
    
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Entered array is:"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i<n/2; i++)
    {
        arr[i] = arr[i] + arr[n-i-1];
        arr[n-i-1] = arr[i] - arr[n-1-i];
        arr[i] = arr[i] - arr[n-i-1];
    }
    
    cout<<"Reversed array is:"<<endl;
    
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}