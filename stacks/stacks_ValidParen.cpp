// stacks

// Prerequisite
// find the ASCII value of all these
// {  - 123
// }  - 125
// (  - 40
// )  - 41
// [  - 91
// ]  - 93

// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;

// -- additional_libraries
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
// -- additional_libraries -- azur3
#include "TimerClock.h"

// Classes

void _input(string &str)
{

    cin >> str;

    // -- optional to get input of multiple line
    // getline(cin, str);
}

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

void validParentheses(string &str)
{

    stack<char> s;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        s.push(str[i]);
    }
    _showStack(s);

    while (!s.empty())
    {
        char prevElement = s.top();
        s.pop();
        char currElement = s.top();

        if (s.empty())
        {
            cout << "Stack is Empty !" << endl;
        }
        cout << "prevElement : " << prevElement << endl;
        cout << "currElement : " << currElement << endl;
        cout << endl;

        if ((currElement == '[') && (prevElement == ']') || (currElement == '{') && (prevElement == '}') || (currElement == '(') && (prevElement == ')'))
        {
            cout << "if condition passed " << endl;
            s.pop();
            continue;
        }
        else
        {
            cout << "if condition not -  passed " << endl;
            cout << ":: Error :: " << endl;
        }
    }
    cout << ":: Perfect String ::" << endl;
}

// Functions

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

    // char var = '}';
    // int value = var;
    // cout << value << endl;
    string str;
    _input(str);
    validParentheses(str);
    // cout << str << endl;

    // Checking Stack Behaviour

#if 0
    stack<int> temp;
    temp.push(1);
    temp.push(2);
    temp.push(3);
    temp.push(4);
    temp.push(5);

    _showStack(temp);
#endif

    return 0;
}