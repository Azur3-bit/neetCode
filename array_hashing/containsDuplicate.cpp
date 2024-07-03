
// simple question - Checks for Duplicate in an array

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
    // Classes
    // Functions

    // printing Vector
    void printVector(vector<int> vec){
        int size = vec.size();
        for(int i=0;i<size;i++){
            cout<<vec[i]<<endl;
        }
        cout << "*** End Of Vector ***" << endl;

    }


    // Duplicate Funtion  
    bool duplicateFuntion(vector <int> nums){
        string ans = "No Repeated Elements";
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){

                ans = "Repeated Elements";
            }
        }
        cout << ans;


    }


    bool containsDuplicate(vector<int>& nums) {
    int size = nums.size();
    // bool ans = false;
    sort(nums.begin(),nums.end());
    for(int i=0;i<size;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
    return false;
        
    }
int main()
{

    // intiliazing a vector 
    vector<int> nums = {1,2,3,4,5,6,7};

    // printVector(nums);
    bool answer =  containsDuplicate(nums);
    cout << answer;



    return 0;
}

// solution by me 

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==nums[i+1]){
//                 return true;
//             }
//         }
//         return false;
//     }
// };


// solution by me that was accecpted 
//         for(int i=0;i<nums.size() - 1;i++){
//                                  ^^^^