// minStack

// desc

// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

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
// Imported from leetcode
class MinStack
{
public:
    MinStack()
    {
    }

    stack<int> minStack{};
    stack<int> minimumElementStack{};

    // new Push Function
    void push(int val)
    {
        minStack.push(val);

        if (minimumElementStack.empty() || val < minimumElementStack.top())
        {
            minimumElementStack.push(val);
        }
        else
        {
            minimumElementStack.push(minimumElementStack.top());
        }
    }

    void push(int val)
    {
        minStack.push(val);
        cout << ":: Element pushed :: " << endl;

        // getting Top element of minimumElementStack
        int top_minimumElementStack = minimumElementStack.top();

        if (val < top_minimumElementStack)
        {
            minimumElementStack.push(val);
        }
        else
        {
            minimumElementStack.push(top_minimumElementStack);
        }
    }

    void pop()
    {
        minStack.pop();
        minimumElementStack.pop();
    }

    int top()
    {
        return minStack.top();
    }

    int getMin()
    {
        return minimumElementStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Functions

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

    MinStack *obj1 = new MinStack();
    obj1->push(-2);
    obj1->push(0);
    obj1->push(-3);

    cout << obj1->getMin() << endl;
    obj1->pop();
    cout << obj1->top() << endl;

    cout << obj1->getMin() << endl;

    return 0;
}