// mohakCode.cpp
#include <iostream>
#include<vector>
using namespace std;

int findMinimumElementInSortedRotated(vector<int> &input){
    if(input.size() == 1) return input[0];
    int low = 0, high = input.size() - 1;
    if(input[low] < input[high]) {
        return input[low];
    }
    while(low <= high){
        int mid =low + (high -low)/2;
        if (input[mid] > input[mid+1]) return input [mid + 1];
        if (input[mid] < input[mid+1]) return input [mid];
        if (input[mid] > input[0]){
             low = mid;
        }else{
            high = mid;
        }
    }
     return -1;
}
int main() {
    int n;
    cin>>n;
        std::vector<int> input;
        for (int i=0; i < n; i++){
             int x;
             cin >> x;
             input.push_back(x);
        }
        cout << findMinimumElementInSortedRotated(input)<<"\n";
        return 0;
}