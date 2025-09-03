/*String Related Programs 
(a) Write a program to concatenate one string to another string. 
(b) Write a program to reverse a string. 
(c) Write a program to delete all the vowels from the string. 
(d) Write a program to sort the strings in alphabetical order. 
(e) Write a program to convert a character from uppercase to lowercase.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    char choice;
    cout << "Choose an option:\n";
    cout << "a) Concatenate strings\n";
    cout << "b) Reverse a string\n";
    cout << "c) Remove vowels from string\n";
    cout << "d) Sort multiple strings\n";
    cout << "e) Convert uppercase to lowercase\n";
    cin >> choice;

    if (choice == 'a') {
        string a, b;
        cin >> a >> b;
        cout << a + b;
    } 
    else if (choice == 'b') {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        cout << s;
    } 
    else if (choice == 'c') {
        string s, result = "";
        cin >> s;
        for (char c : s) {
            if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                  c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
                result += c;
        }
        cout << result;
    } 
    else if (choice == 'd') {
        int n;
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (string s : arr) cout << s << " ";
    } 
    else if (choice == 'e') {
        char c;
        cin >> c;
        if (c >= 'A' && c <= 'Z') c = c + 32;
        cout << c;
    } 
    else {
        cout << "Invalid choice";
    }

    return 0;
}
