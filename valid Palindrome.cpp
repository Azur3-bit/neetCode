// valid Palindrome
// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

// Functions

bool ValidPalindrome(string &str)
{

    cout << "Entered String : " << str << endl;
    int i = 0;
    int j = str.size() - 1;

    cout << "last element : " << str[j] << endl;

    while (i < j)
    {
        int i_Element = str[tolower(i)];
        int j_Element = str[tolower(j)];

        cout << i_Element << " -- " << j_Element << endl;

        if (i_Element != j_Element)
        {
            cout << "not a palindrom " << endl;
            return false;
        }
        j--;
        i++;
    }

    cout << "palindrome" << endl;
    return true;
    // cout << "not valid Palindrome" << endl;
}

int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // -- faster I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // -- Main Function code --

    // string name;
    // cin >> name;
    // cout << "hello "<< name;

    // string palin;
    // puts(palin);
    string palin = "A man, a plan, a canal: Panama";
    // cout << "Answer " << ValidPalindrome(palin);

    ValidPalindrome(palin);

    return 0;
}