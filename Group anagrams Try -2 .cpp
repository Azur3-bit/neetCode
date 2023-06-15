// Group anagrams

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <set>

// Classes

// Functions

// Funtion to Traverse vector
void showVector(vector<string> temp)
{
    cout << "\t\t:: Printing Vector ::"
         << "\n";
    int size = temp.size();
    for (int i = 0; i < size; i++)
    {
        cout << temp[i] << endl;
    }
    cout << "\t\t:: Vector has been Printed :: "
         << "\n";
}

vector<string> SortingFunc(vector<string> &vecString)
{
    sort(vecString.begin(), vecString.end());
    return vecString;
}

void Solution(vector<string> vecString)
{

    map<string, int> hashMap;
    int size = vecString.size();
    for (int i = 0; i < size; i++)
    {
        int TotalSizeOfWord = 0;
        string CurrentWord = vecString[i];
        int CurrentSize = CurrentWord.size();
        // for (int j = 0; j < CurrentSize;j++){

        //     hashMap[vecString[i]] =
        // }
    }
}

int main(int argc, char const *argv[])
{
    // Main Code Function

    vector<string> strVec = {"eat", "tea", "tan", "ate", "nat", "bat"};

    showVector(strVec);

    vector<string> strTest = {"aaa", "aa", "a"};
    string str_1 = strTest[0];
    string str_2 = strTest[1];

    int Element_1Size = sizeof(str_1);
    int Element_2Size = sizeof(str_2);
    cout << str_1 << " ELement_1size " << Element_1Size << endl;
    cout << str_2 << " ELement_2size " << Element_2Size << endl;
    // cout << "word_2size" << word_1size;

    // Sorting Vector
    // SortingFunc(strVec);
    // showVector(strVec);

    return 0;
}