// Daily Temperatures

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

template <typename KeyType, typename ValueType>
void _showHashMap(const std::unordered_map<KeyType, ValueType> &hashMap)
{
    std::cout << std::endl;
    std::cout << "-*-  -*- -*- " << std::endl;
    std::cout << "Printing HashMap" << std::endl;
    std::cout << std::endl;
    std::cout << "key\t\tvalue" << std::endl;
    std::cout << "----\t-----" << std::endl;

    for (const auto &it : hashMap)
    {
        std::cout << it.first << "\t\t" << it.second << std::endl;
    }

    std::cout << std::endl;
    std::cout << "HashMap Printed" << std::endl;
    std::cout << "-*-  -*- -*- " << std::endl;
    std::cout << std::endl;
}

// funtion to print a stack of pair

void _showPairStack(stack<pair<int, int>> &pairStack)
{
    std::cout << std::endl;
    std::cout << "-*-  -*- -*- " << std::endl;
    std::cout << "Printing HashMap" << std::endl;
    std::cout << std::endl;
    std::cout << "first\tsecond" << std::endl;
    std::cout << "----\t-----" << std::endl;

    while (!pairStack.empty())
    {
        pair<int, int> currElement = pairStack.top();
        cout << currElement.first << "\t\t" << currElement.second << endl;
        pairStack.pop();
    }
    std::cout << std::endl;
    std::cout << "HashMap Printed" << std::endl;
    std::cout << "-*-  -*- -*- " << std::endl;
    std::cout << std::endl;
}

vector<int> dailyTemp(vector<int> &temp)
{

    stack<pair<int, int>> hashStack{};
    int size = temp.size() - 1;
    cout << "size : " << size << endl;
    for (int i = size; i >= 0; i--)
    {
        hashStack.push(pair<int, int>(i, temp[i]));
    }
    _showPairStack(hashStack);
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

    vector<int> temp{};
    _input(temp);
    _showVector(temp);

    dailyTemp(temp);
    return 0;
}