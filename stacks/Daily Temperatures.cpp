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
    std::cout << endl;
}

template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
    std::cout << ":: Printing Vector :: " << endl;
    std::cout << "{ ";
    for (type_2 it : nums)
    {
        std::cout << it << " ";
    }
    std::cout << "}";
    std::cout << endl;
    std::cout << ":: Vector Printed :: " << endl;
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
        std::cout << currElement.first << "\t\t" << currElement.second << endl;
        pairStack.pop();
    }
    std::cout << std::endl;
    std::cout << "HashMap Printed" << std::endl;
    std::cout << "-*-  -*- -*- " << std::endl;
    std::cout << std::endl;
}

vector<int> dailyTemp(vector<int> &temp)
{

    stack<pair<int, int>> stackMap{};
    vector<int> answer(temp.size(), 0);
    // _showVector(temp);
    // _showVector(answer);

    int size = temp.size() - 1;

    // pushing last element in the stack
    pair<int, int> lastElement = pair<int, int>(temp[size], size);
    stackMap.push(lastElement);
    // std::cout << lastElement.first << " " << lastElement.second << endl;

    for (int i = size - 1; i >= 0; i--)
    {
        pair<int, int> currentElement = pair<int, int>(temp[i], i);
        // std::cout << "\n currentElement : " << currentElement.first << " " << currentElement.second << endl;

        pair<int, int> topElement = stackMap.top();
        // std::cout << "topElement : " << topElement.first << " " << topElement.second << endl;

        // std::cout << "Breakpoint - 1" << endl;

        if (stackMap.empty() || currentElement.first < stackMap.top().first)
        {

            int diff = stackMap.top().second - currentElement.second;

            // std::cout << "Difference - 1 : " << diff << endl;
            answer[currentElement.second] = diff;

            // std::cout << "Pushing item :: " << currentElement.first << endl;
            stackMap.push(currentElement);
            // answer[currentElement]
        }
        if (currentElement.first > stackMap.top().first)
        {
            while (!stackMap.empty())
            {
                if (currentElement.first > stackMap.top().first)
                {
                    // std::cout << "poping !" << endl;
                    stackMap.pop();
                }
                else if (currentElement.first < stackMap.top().first)
                {
                    // std::cout << "elseif condition inside while loop " << endl;

                    int diff = stackMap.top().second - currentElement.second;

                    // std::cout << "Difference - 2 : " << diff << endl;

                    // std::cout << "Pushing item :: " << currentElement.first << endl;
                    stackMap.push(currentElement);
                    answer[currentElement.second] = diff;
                    break;
                }
            }

            if (stackMap.empty())
            {
                // std::cout << "after pushing " << currentElement.second << " is 0 " << endl;
                stackMap.push(currentElement);
            }
        }
    }
    return answer;
}

// try - 2 dailTemp
vector<int> dailyTemp_try2(vector<int> &temp)
{

    stack<pair<int, int>> stackMap{};
    vector<int> answer(temp.size(), 0);

    std::cout << "Entered Vector : " << endl;
    _showVector(temp);
    std::cout << "stackMap: " << endl;
    _showPairStack(stackMap);
    std::cout << "answer Vector: " << endl;
    _showVector(answer);

    int size = temp.size();
    pair<int, int> lastElement = pair<int, int>(temp[size - 1], size - 1);

    std::cout << "last Element : " << lastElement.first << " <-> " << lastElement.second << endl;

    std::cout << "Pushing last Elment in the stack " << endl;
    stackMap.push(lastElement);

    // _showPairStack(stackMap);

    // std::cout << "Elment at top of the stack : " << stackMap.top().first << " -- " << stackMap.top().second << endl;

    std::cout << " -- LOOP -- " << endl;
    for (int i = size - 2; i >= 0; i--)
    {
        int item = temp[i];
        int index = i;
        pair<int, int> currElement = pair<int, int>(item, index);
        pair<int, int> topElement = stackMap.top();

        std::cout << "Element At top the stack : " << topElement.first << " -> " << topElement.second << endl;

        std::cout << "Current Element : " << currElement.first << " -- " << currElement.second << endl;

        if (currElement.first < topElement.first)
        {
            stackMap.push(currElement);
            std::cout << "\t\tdifferece : " << topElement.second - currElement.second << endl;
        }

        if (currElement.first <= topElement.first)
        {
            stackMap.pop();
        }

#if 0

//  base case
        if (stackMap.empty())
        {
            answer[currElement.second] = 0;
        }
#endif
    }
}

vector<int> dailyTemptry_1(vector<int> &temp)
{

    stack<pair<int, int>> hashStack{};

    vector<int> ans(temp.size(), 0);

    // printing answer vector
    std::cout << "\n -- ** -- Answer -- ** --\n\n";
    _showVector(ans);
    std::cout << "\n -- ** -- Answer -- ** --\n\n";

    int size = temp.size() - 1;
    std::cout << "size : " << size << endl;
    for (int i = size; i >= 0; i--)
    {
        pair<int, int> currElement = pair<int, int>(i, temp[i]);
        pair<int, int> currTopElement = hashStack.top();

        //  -- Personal Check point current Element and element on top of stack
        // current Top Elment

        std::cout << "Current Element : \t";
        std::cout << currElement.first << " -- " << currElement.second << endl;
        // std::cout << "Current Top Elment : " << endl;
        std::cout << "current top element : " << currTopElement.first << "\t\t" << currTopElement.second << endl;
        std::cout << endl;
        hashStack.push(pair<int, int>());

        if (currElement.second < currTopElement.second)
        {
            std::cout << "IF statement " << endl;
            // std::cout << "bigger Element Found ! "
            //      << "currElement.second " << currElement.second << "currTopElement.second " << currTopElement.second << "\n -- Difference : " << currElement.first - currTopElement.first << endl;
        }
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
    vector<int> ans(temp.size(), 0);

    ans = dailyTemp(temp);

    _showVector(ans);
    return 0;
}