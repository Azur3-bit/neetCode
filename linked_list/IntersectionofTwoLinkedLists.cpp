/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        map<ListNode *, int> mpp {};

        ListNode * tempA = headA;
        ListNode * tempB = headB;

        while(tempA != nullptr || tempB != nullptr){
            
            
            if(tempA != nullptr){

                if(mpp.find(tempA) != mpp.end()){
                    return tempA;
                }
                mpp[tempA]++;
                tempA = tempA->next;

            }


            if(tempB != nullptr){

                if(mpp.find(tempB) != mpp.end()){
                    return tempB;
                }
                mpp[tempB]++;
                tempB = tempB->next;
            }
        
        }

        return nullptr;

        
    }
};