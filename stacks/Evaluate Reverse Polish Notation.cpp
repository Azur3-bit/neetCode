// Evaluate Reverse Polish Notation

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

template <typename type_1>
void _input(vector<type_1> &nums)
{

    // take a single line for input
    // traverse it and push all the elements into the vector of stirng
    type_1 input;
    while (cin >> input)
    {
        nums.push_back(input);
    }
    cout << endl;
}

template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
    cout << ":: Printing Vector :: " << endl;
    cout << "{ ";
    for (type_2 it : nums)
    {
        cout << it << " ";
    }
    cout << "}";
    cout << endl;
    cout << ":: Vector Printed :: " << endl;
}

void selfhelpFuntion()
{

    char add = '+';
    char sub = '-';
    char div = '/';
    char mul = '*';
    int addAscii = add;
    int subAscii = sub;
    int divAscii = div;
    int mulAscii = mul;
    cout << add << " - > " << addAscii << endl;
    cout << sub << " - > " << subAscii << endl;
    cout << mul << " - > " << mulAscii << endl;
    cout << div << " - > " << divAscii << endl;
}

void RevPolishNotiaion(vector<string> &tokens)
{

    // stacks for getting all the elements together
    stack<string> RPN{};
    // pushing valid values in the stacks
    for (string it : tokens)
    {
        if ((it == "*") || (it == "+") || (it == "/") || (it == "-"))
        {
            string op_2 = RPN.top();
            int intOP_2 = stoi(op_2);
            RPN.pop();
            string op_1 = RPN.top();
            int intOP_1 = stoi(op_1);
            RPN.pop();

            if (it == "*")
            {
                int result = intOP_1 * intOP_2;

                RPN.push(to_string(result));
            }

            if (it == "+")
            {
                int result = intOP_1 + intOP_2;
                RPN.push(to_string(result));
            }

            if (it == "-")
            {
                int result = intOP_1 - intOP_2;
                RPN.push(to_string(result));
            }

            if (it == "/")
            {
                int result = intOP_1 / intOP_2;
                if (result == 0)
                {
                    RPN.push("0");
                }
                else
                {
                    // string strResult = ;
                    RPN.push(to_string(result));
                }
            }
        }

        else
        {
            RPN.push(it);
        }
    }
    cout << "result : " << stoi(RPN.top()) << endl;
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

    // run for multiple inputs

    vector<string> tokens{};
    _input(tokens);
    _showVector(tokens);
    RevPolishNotiaion(tokens);
#if 0
    // checking string comparions
    string s = "*";
    string q = "*";
    if (s == "*")
    {
        cout << "They both are Equal " << endl;
    }
    else
    {
        cout << "They both are not - Equal " << endl;
    }
#endif

    return 0;
}
