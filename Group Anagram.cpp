// Group Anagram

// Question Description
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

// Functions

// printing Vector

void ShowVector(vector<string> vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}

void ShowVectorComplex(vector<vector<string>> StringVector)
{

    for (int i = 0; i < int(StringVector.size()); i++)
    {
        vector<string> currentVector = StringVector[i];
        string CurrentElement = currentVector[i];
        for (int j = 0; j < currentVector.size(); j++)
        {
            cout << "Index :: " << i << " -> " << j;
            cout << " <_> ELement : " << currentVector[j] << endl;
        }
        break;
    }
}

void PrintingHashMap(auto HashMap)
{

    cout << "Key"
         << "\t\t"
         << "Value" << endl;
    for (auto it : HashMap)
    {
        cout << it.first << "\t\t" << it.second << endl;
    }
}

// Finding HashMap Values
void Solution(vector<string> StringVector)
{

    // vector<string> anagrams = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // "eat"
    map<string, int> HashMap;
    map<int, string> tempHashMap;
    // vector<vector<string>> result;

    for (int i = 0; i < (int)StringVector.size(); i++)
    {
        int currentElementCharacterLenght = 0;
        string currentElement = StringVector[i];

        for (int j = 0; j < (int)currentElement.size(); j++)
        {
            currentElementCharacterLenght += (int)currentElement[j];
        }
        HashMap[StringVector[i]] = currentElementCharacterLenght;
        tempHashMap[currentElementCharacterLenght] = StringVector[i];
    }
    cout << "Principal Hashmap " << endl;
    PrintingHashMap(HashMap);
    cout << "temporary Hashmap " << endl;
    PrintingHashMap(tempHashMap);
    // Grouping Anagrams with Respect to their key Values
    // batch - 1

    // vector<vector<string>>;
    for (int i = 0; i < (int)HashMap.size(); i++)
    {
        vector<string> result = {};
        map<string, int>::iterator iter;
        int currentKey = iter->second;
        cout << "current :: " << currentKey << endl;
        for (auto it : HashMap)
        {

            cout << "it.second :: " << it.second << endl;

            if (it.second == currentKey)
            {
                cout << "Value :: " << it.first << endl;
                // result.push_back(it.first);
            }
        }
        // ShowVector(result);
    }
}

int main()
{
    // Main Code Function

    vector<string> anagrams = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // ShowVector(anagrams);
    // char CharacterString = 'a';
    // cout << int(CharacterString) << endl;
    Solution(anagrams);

    return 0;
}