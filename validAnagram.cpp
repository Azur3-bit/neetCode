// Valid anagram

// s = rat
// t = fjkahfk__rat__hhsdf

// approach - 1
// sort both the string and check if they are equal

#include <iostream>
#include <algorithm>
using namespace std;
// Classes
// Functions

bool validAnagram(string s, string t)
{

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int size = t.size();

    cout << "Size : " << size << endl;

    for (int i = 0; i < size; i++)
    {
        if (s[i] == t[i])
        {
            cout << "True" << endl;
            cout << s[i] << "and" << t[i];
            // ans = true;
        }
        else
        {

            cout << "False" << endl;
            cout << s[i] << " and " << t[i];
            // ans = false;
            return false;
        }
    }
    return true;

    cout << "True";
    return 0;
}

int main()
{
    // Main Code Function
    string s = "Rahul";
    string t = "Rahul";

    validAnagram(s, t);
}