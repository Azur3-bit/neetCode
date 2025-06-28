/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */


Node * MergeTwo(Node *t1 , Node *t2){
	// helper function


	Node * head = new Node(-1);
	Node * temp = head;

	while(t1 && t2){
		
		if(t1->data < t2->data){
			temp->child = t1;
			temp = t1;
			t1 = t1->child;
		}
		else{
			temp->child = t2;
			temp = t2;
			t2 = t2->child;
		}
	}

	if(t1){
		temp->child = t1;
	}
	else{
		temp->child = t2;
	}

	
	return head->child; // (okay)  i was returning head->next (wrong)

}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here

	if(head == nullptr || head->next == nullptr)
		return head;

	Node * rec = flattenLinkedList(head->next);
	head->next = nullptr; // (okay) added this why ??
	Node * merge = MergeTwo(rec, head); 

	return merge;



}
