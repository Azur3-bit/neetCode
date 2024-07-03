// consecutiveNumbers using HashMap

//  -- test Case - 1
// 100 4 200 1 3 2  -    o/p 4

//  -- test Case - 2
// 0 3 7 2 5 8 4 6 0 1 - o/p 9

//  -- test Case - 3
//  9 1 4 7 3 -1 0 5 8 -1 6  - o/p 7

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
template <typename type_1>
void _input(vector<type_1> &nums)
{
    type_1 input;
    while (cin >> input)
    {
        nums.push_back(input);
    }
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
    cout << ":: Vector Printed :: ";
}

template <typename KeyType, typename ValueType>
void _showHashMap(const std::map<KeyType, ValueType> &hashMap)
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

template <typename T>
void _showUnOrderedSet(const std::unordered_set<T> &numsSet)
{
    std::cout << "-*-  -*- -*-" << std::endl;
    std::cout << "Printing Set" << std::endl;
    std::cout << std::endl;
    std::cout << "{ ";
    for (auto it = numsSet.begin(); it != numsSet.end(); ++it)
    {
        std::cout << *it;
        if (std::next(it) != numsSet.end())
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    std::cout << "-*-  -*- -*-" << std::endl;
}
template <typename T>
void _showSet(const std::set<T> &numsSet)
{
    std::cout << "-*-  -*- -*-" << std::endl;
    std::cout << "Printing Set" << std::endl;
    std::cout << std::endl;
    std::cout << "{ ";
    for (auto it = numsSet.begin(); it != numsSet.end(); ++it)
    {
        std::cout << *it;
        if (std::next(it) != numsSet.end())
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    std::cout << "-*-  -*- -*-" << std::endl;
}

void matrixProblem()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << (i / 3) * 3 + (j / 3) << " ";
        }
        cout << endl;
    }
}

int consecutiveOccrance(vector<int> &nums)
{
    // using vector to store all the counter values
    vector<int> allCounterValues{}; // * - not needed now
    set<int> allCounterValuesSet{};
    // using set instead of vector to store all the values
    set<int> hashSet{};
    map<int, bool> hashmap{}; // * - not needed now
    int occranceCounter = 0;
    if (nums.size() == 0)
    {
        return occranceCounter;
    }
    for (int it : nums)
    {
        hashSet.insert(it);
    }
    std::cout << "-*-  -*- #1 START -*-" << std::endl;
    cout << "breakpoint - 1" << endl;
    _showSet(hashSet);
    std::cout << "-*-  -*- # 1 END -*-" << std::endl;

    // * Done till here

    // TODO Problem -- Prev elment has to be take in count maybe
    // TODO [9,1,4,7,3,-1,0,5,8,-1,6]

#if 0
    for (int it : nums)
    {
        hashmap[it] = true;
    }
#endif
    // _showHashMap(hashmap);
    for (auto it : hashSet)
    {
        int prevElement = it - 1;
        int nextElement = it + 1;

        if (hashSet.find(prevElement) != hashSet.end() && hashSet.find(nextElement) != hashSet.end())
        {
            cout << "--- --- --- ---" << endl;
            cout << prevElement << " -> ";
            cout << "for item - " << it << " <- ";
            occranceCounter++;
            cout << nextElement << " " << endl;
            cout << "current counter " << occranceCounter;
            cout << endl;
            // allCounterValues.push_back(occranceCounter);
            allCounterValuesSet.insert(occranceCounter);
        }
    }
    // Printing the entire set
    _showSet(allCounterValuesSet);
    auto maxElement = allCounterValuesSet.end();
    cout << "Maxiumum Occarnce : " << *maxElement + 1;
    return +1;
}

void approach2_ConsecutiveSequence(vector<int> &nums)
{

    // creating a set to store all the values
    unordered_set<int> userSet{};

    // int answer;
    for (int it : nums)
    {
        userSet.insert(it);
    }
    int maxConsecutiveSequence = 0;
    // -- Printing Set
    // _showUnOrderedSet(userSet);

    for (int number : nums)
    {
        if (userSet.find(number - 1) == userSet.end())
        {
            int currNumber = number;
            int currentConsecutiveSequnce = 1;

            while (userSet.find(currNumber + 1) != userSet.end())
            {
                currNumber++;
                currentConsecutiveSequnce++;
            }

            // maximum Consecutive Sequence
            maxConsecutiveSequence = max(currentConsecutiveSequnce, maxConsecutiveSequence);
        }
    }
    cout << "maximum Consecutive Sequence : " << maxConsecutiveSequence << endl;
    // return maxConsecutiveSequence;
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
    // -- input vector by input file
    vector<int> nums;
    _input(nums);

    // -- Actual funciton code
    // consecutiveOccrance(nums);
    approach2_ConsecutiveSequence(nums);

    // -- after sorting
    // sort(nums.begin(), nums.end());
    // _showVector(nums);

#if 0
    cout << "\n-- Matrix issue -- \n";
    matrixProblem();
    cout << "\n-- Matrix issue -- \n";
#endif

    return 0;
}