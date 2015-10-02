#include <iostream>


class solution {

public:
void reverseiteration(Node* head) {
	Node* fast=head;
	Node* slow=head;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* curr=slow->next;
	Node* prev=NULL;
	while (curr){
		Node* next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	slow->next=prev;
	
}

private: int len,half;

public:
	Node* reverserecursion(Node* head){
		if (head==NULL||head->next==NULL){
			half=len/2;
			return head;
		}
		len++;
		Node* newhead=reverserecursion(head->next);
		if (half>0){
			head->next->next=head;
			head->next=NULL;
			half--;
			return newhead;
		}
		else {
			head->next=newhead;
			return head;
		}
	}

};