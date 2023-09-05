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
// show linked list
void _showLinkedList(ListNode * head) {
   while (head) {
      cout << head->val << " -> ";
      head = head->next;
   }
   cout << "null\n";
}
// show linked list using vector
void _showLinkedList_using_vector(const vector<ListNode *> & nums) {
   for (auto it : nums)
      _showLinkedList(it);
   cout << "printed linked list using vector format ! \n";
}
// show vector
template <typename type_2>
void _showVector(const vector<type_2> &nums)
{
   cout << ":: Printing Vector :: " << endl;
   cout << "{ ";
   for (type_2 it : nums)
   {
      cout << it << " ";
   }
   cout << "}";
   cout << endl;
}
void modi_showVector(vector <pair<int, ListNode *>> &nums)
{  cout << "int\tListNode *\n";
   for (auto it : nums) {
      cout << it.first << "\t" << it.second << endl;
   }
}
// fucnction to get the address of the nodes of linked list
void _show_add_linkedList(vector<ListNode * > & nums) {
   for (auto it : nums) {
      int c = 0;
      while (it) {
         cout << ++c << ". it.add : " << it << endl;
         it = it->next;
      }
      cout << "   \n";
   }
}
// Actual solution function
ListNode* mergeKsortedList(vector<ListNode * > & list) {
   cout << "answer Fucntion \n";
   cout << "-------- SOLUTION --------\n";
   // _showLinkedList_using_vector(list);
   vector<pair<int, ListNode * >> v {};
   vector<ListNode * >v_nodes {} ;
   // modi_showVector(v);
   cout << "-------- _ SOLUTION _ --------\n";
   for (auto it : list) {
      while (it) {
         cout << "it.add : " << it << endl;
         v.push_back(make_pair(it->val, it));
         v_nodes.push_back(it);
         it = it->next;
      }
   }
   _showVector(v_nodes);
   modi_showVector(v);
   cout << "\nPair Sorting\n";
   cout << "------------\n\n";
   sort(v.begin() , v.end());
   modi_showVector(v);
   if (v.empty())
      return nullptr;
   ListNode * head = v[0].second;
   ListNode * temp_head = head;
   for (int i = 1 ; i < v.size(); i++) {
      temp_head->next = v[i].second;
      temp_head = temp_head->next;
   }
   return head;
}

int main(int argc, char const * argv[])
{
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif
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

   cout << "first_1 : " << first_1 << endl;
   // prints the address of the node

   vector<ListNode *> nums = {first, first_1, second_2};
   _showLinkedList_using_vector(nums);
   _show_add_linkedList(nums);
   cout << "------------------------------------\n";
   // ListNode * ans = mergeKLists(nums);
   ListNode * ans =  mergeKsortedList(nums);
   // test modi vector Show using ListNode *
   cout << "------------------------------------\n";
   cout << "final answer :-> \n";
   _showLinkedList(ans);

   return 0;
}
