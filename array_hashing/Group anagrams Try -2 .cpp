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

// Show HashMap

void ShowHashMap(map<string, int> HashMap)
{

    cout << "Key"
         << "\t\t"
         << "Value" << endl;

    for (auto it : HashMap)
    {
        cout << it.first << "\t\t" << it.second << endl;
    }
}

void creatingHashMap(vector<string> vecString)
{

    map<string, int> hashMap;
    int size = vecString.size();

    // Getting the size of each word
    for (int i = 0; i < size; i++)
    {
        string currentWord = vecString[i];
        // int currentWordSize = 0;
        int currentWordLenght = currentWord.size();
        int currentWordSize = 0;

        cout << "Lenght of : " << currentWord << " is - " << currentWordLenght << endl;
        for (int j = 0; j < currentWordLenght; j++)
        {

            int tempSize = currentWord[j];
            currentWordSize += tempSize;
        }
        hashMap[vecString[i]] = currentWordSize;
    }
    ShowHashMap(hashMap);


    // Grouping Elements based on their Value - Scrapped Because it worsen the time complexity 
    // while is already (n*m)
    // n - total number of element in the list 
    // m - size of each character in the list 

    // Still trying to find the solution

    // for (int i = 0; i < vecString.size();i++){
    //     vector<string> solution = {};
        


    // }


}

int main(int argc, char const *argv[])
{
    // Main Code Function

    vector<string> strVec = {"eat", "tea", "tan", "ate", "nat", "bat"};

    showVector(strVec);

    vector<string> strTest = {"aaa", "aa", "a"};
    string str_1 = strTest[0];
    string str_2 = strTest[1];

    // int Element_1Size = sizeof(str_1);
    // int Element_2Size = sizeof(str_2);
    // cout << str_1 << " ELement_1size " << Element_1Size << endl;
    // cout << str_2 << " ELement_2size " << Element_2Size << endl;
    // cout << "word_2size" << word_1size;

    // Sorting Vector
    // SortingFunc(strVec);
    // showVector(strVec);

    creatingHashMap(strVec);

    return 0;
}