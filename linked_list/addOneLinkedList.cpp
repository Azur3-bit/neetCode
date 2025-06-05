/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


int helper(Node * head){

    if(head == nullptr){
        return 1;
    }


    int carry = helper(head->next);

    if(carry == 0){
        return 0;
    } 

    int val = head->data;
    val += carry;

    if(val > 9){
        head->data = 0;
        return 1;
    }

    head->data = val;

    return 0;

}

Node *addOne(Node *head)
{
    // Write Your Code Here.


    int res = helper(head);


    if(res == 1){
        Node* newNode = new Node(1);
        newNode->next = head;

        head = newNode; 
    }

    return head;




}
