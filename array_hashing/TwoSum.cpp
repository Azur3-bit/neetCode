// two sum - Leetcode


// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


// Brute Force Solution Not the Optimal Solution

//? Todo - Learn About hashMaping 
//?        unOrdered Maps
//?        Ordered Maping 



#include <bits/stdc++.h>
#include <vector>
using namespace std;
    // Classes
    // Functions

    void TraverseVector(vector<int> temp){ 
        cout << endl;
        cout << endl;
        // cout << endl;

        cout << "*** Start of Vector ***" << endl;
        int size = temp.size(); 

        for(int i = 0;i<size;i++){
            cout << temp[i] << endl;
        }
        cout << "*** End of Vector ***" << endl;
        // cout << endl;
        cout << endl;
        cout << endl;
    }

    // funtion to check for two sum = target 

    void TwoSum(vector<int> nums, int target){


        int size = nums.size();
        cout << size; 

        int a = 0;
        cout << endl;
        while(size--){
            cout << "Size of this Iteration is :: " << size << endl;
            int pickedElement = nums[a];
            cout << "element choosen is :: " << pickedElement << endl;
            int elementTobePicked = target - pickedElement;
            cout << "Element that has to be found in the vector is :: "<< elementTobePicked;

            for(int i = 0;i<size;i++){

                if(elementTobePicked == nums[i]){
           
                    cout << "Value of i "<< i << endl;
                    cout << "Value of a "<< a << endl;
                    // cout << endl;
                    // cout << endl;
                    cout << endl;
                    cout << "\t\tElement at " << a << " and " << i << " add upto " << "target "<< target <<endl;  
                    cout << "Element picked at starting :: " << pickedElement<<endl;

                    cout << "Element after selection is  :: " << nums[i]<<endl; 
                }
                // break; 
                // <-  add break for single answer single answer 

            }
            a++;
            cout << "Value of a incremented in outside for loop statement, a = " << a << endl; 
        }


    }


int main()
{
    // Main Code Function
                    // 0 1 2 3 4 5 6
    vector<int> num = {1,2,3,4,5,6,7};
    TraverseVector(num);
    TwoSum(num,3);


    return 0;
}