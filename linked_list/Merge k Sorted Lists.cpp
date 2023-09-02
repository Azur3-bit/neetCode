// Merge k Sorted Lists


// -- essential_libraries_and_namespace
#include <iostream>
using namespace std;
// #include <math>

// -- additional_libraries
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <array>
#include <unordered_map>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>

// -- additional_libraries -- azur3
#include "TimerClock.h" // For Performance Monitor

// Classes
struct ListNode {
   int val;
   ListNode * next;
   ListNode * prev;
   ListNode() : val(0) , next(nullptr) , prev(nullptr) {}
   ListNode(int _val ) : val(_val) , next(nullptr) , prev(nullptr) {}
   ListNode(int _val , ListNode * nxt , ListNode * pre ) : val(_val) , next(nxt) , prev(pre) {}
};

// Functions
void _showLinkedList(ListNode * head) {
   while (head) {
      cout << head->val << " -> ";
      head = head->next;
   }
   cout << "null\n";
}

// solutions -> approaches possible
// [simple] use a ordered hashMap to store all the nodes and their values as key and add them in order in the linked list
// [complex] sorting Linked list after connecting all the last nodes of the linked list


void _showLinkedList_using_vector(const vector<ListNode *> & nums) {
   for (auto it : nums)
      _showLinkedList(it);
   cout << "printed linked list using vector format ! \n";
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif

   // -- faster I/O operations
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   // -- Main Function code --
   ListNode * first = new ListNode(1);
   ListNode * forth = new ListNode(4);
   ListNode * fifth = new ListNode(5);
   // linking
   first->next = forth;
   forth->next = fifth;
   fifth->next = nullptr;

   ListNode * first_1 = new ListNode(1);
   ListNode * third_1 = new ListNode(3);
   ListNode * forth_1 = new ListNode(4);

   // linking
   first_1->next = third_1;
   third_1->next = forth_1;
   forth_1->next = nullptr;

   ListNode * second_2 = new ListNode(2);
   ListNode * sixth_2 = new ListNode(6);
   // linking
   second_2->next = sixth_2;
   sixth_2->next = nullptr;

   // linking heads
   ListNode * head_1 = first;
   ListNode * head_2 = first_1;
   ListNode * head_3 = second_2;

   // vector<ListNode * > = {{1, 4, 5}, {1, 3, 4}, {2, 6}}


   // _showLinkedList(head_1);
   // _showLinkedList(head_2);
   // _showLinkedList(head_3);
   // cout << "END\n";
   vector<ListNode *> nums = {head_1, head_2, head_3};
   _showLinkedList_using_vector(nums);

   return 0;
}
