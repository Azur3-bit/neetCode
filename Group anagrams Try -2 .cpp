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




vector<string> SortingFunc(vector<string> &vecString){
    sort(vecString.begin(), vecString.end());
    return vecString;
}


void Solution(vector<string> vecString){

    map<string, string> hashMap;
    int size = vecString.size();
    // for (int i = 0; i < size;i++){
    //     hashMap[vecString[i]] = 
    // }
}

int main(int argc, char const *argv[])
{
    // Main Code Function

    vector<string> strVec = {"eat", "tea", "tan", "ate", "nat", "bat"};

    showVector(strVec);

    
    // Sorting Vector
    // SortingFunc(strVec);
    // showVector(strVec);

    return 0;
}