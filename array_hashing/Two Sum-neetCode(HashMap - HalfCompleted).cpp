// Two Sum

#include <iostream>
using namespace std;

// additional_libraries
#include <vector>
#include <array>
#include <unordered_map>
// #include <map>
// #include <set>

// Input
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Classes

// Functions

// Funtion to Enter VALues in NUMS - Vector

vector<int> EnterValue(vector<int> &temp)
{

    cout << "Enter NUmber of Values To be Entered : " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cout << "Enter Value to be Inputed in the Nums Vector " << endl;
        cin >> input;
        temp.push_back(input);
    }
    return temp;
}

// Mapping Values of nums to hashcode

unordered_map<int, int> Hashcode(vector<int> temp)
{

    unordered_map<int, int> hash;

    int size = temp.size();
    for (int i = 0; i < size; i++)
    {
        int code = temp[i] % size;
        hash.insert(pair<int, int>(code, temp[i]));
    }
    return hash;
}

int TwoSum(vector<int> nums, unordered_map<int, int> hashCodeMap, int target)
{

    int size = nums.size();
    cout << "Size :" << size;
    int i = 0;
    while (size--)
    {
        cout << endl;
        cout << "\tLoop Iteration : " << i << endl;

        // int element = nums[i];
        int ElementToBeFounded = target - nums[i];

        cout << "Element to be Founded : " << ElementToBeFounded << endl;
        auto valueByFind = hashCodeMap.find(ElementToBeFounded);
        int number = valueByFind->second;
        // cout << "For " << nums[i] << " Value By find()->first : " << valueByFind->first << endl;
        if (ElementToBeFounded == number)
        {
            cout << "For " << nums[i] << " Value By find()->second : " << valueByFind->second << endl;
            break;
        }
        else
        {
            cout << "Inside Else Block : : " << endl;
            i++;
        }
    }
}

// Printing A vector

void PrintingVector(vector<int> nums)
{
    cout << "Printing vector " << endl;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << "\n";
    }
}

// Printing Hashcode

void PrintHashCode(unordered_map<int, int> Map)
{
    cout << "Printing Map " << endl;
    cout << "UserInputed_Value"
         << "\t"
         << "Hashcode" << endl;

    // unordered_map<int, int>::iterator i = Map.begin();
    for (auto i : Map)
    {
        cout << i.first << "\t\t\t" << i.second << "\n";
    }
}

int main(int argc, char const *argv[])
{
    // Main Code Function

    vector<int> nums = {1, 2, 3, 4, 5};
    int target;
    cout << "Enter target Value After Sum : "
         << "\n";
    cin >> target;

    unordered_map<int, int> HashcodeMap;
    // EnterValue(nums);
    // PrintingVector(nums);

    HashcodeMap = Hashcode(nums);
    PrintHashCode(HashcodeMap);

    int result = TwoSum(nums, HashcodeMap, target);
    // cout << result << endl;
    return 0;
}