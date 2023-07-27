// stack_validParentheses Try - 2
// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
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

template <typename t>
void _showStack(const stack<t> &stac)
{
    cout << "-- -- -- -- -- -- " << endl;
    cout << "printing Stack " << endl;
    cout << "-- -- -- -- -- -- " << endl;

    stack<t> tempStack = stac;

    while (!tempStack.empty())
    {
        cout << tempStack.top() << endl;
        tempStack.pop();
    }

    cout << "-- -- -- -- -- -- " << endl;
    cout << "Stack printed " << endl;
    cout << "-- -- -- -- -- -- " << endl;
}

void ValidParenthesis(string &s)
{
    stack<char> s1;
    for (char letter : s)
    {

        if ((letter == '[') || (letter == '{') || (letter == '('))
        {
            cout << "Pushing " << endl;
            s1.push(letter);
        }
        else
        {
            if (s1.empty() ||
                (letter == ']' && s1.top() != '[') ||
                (letter == ')' && s1.top() != '(') ||
                (letter == '}' && s1.top() != '{'))

            {
                cout << "Error " << endl;
                return;
            }
            s1.pop();
        }
    }
    cout << ":: Correct String :: " << endl;
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

#if 0
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    _showStack(s);
#endif

    string s;
    cin >> s;
    ValidParenthesis(s);

    return 0;
}