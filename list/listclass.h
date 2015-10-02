#include <iostream>
using namespace std;

class Node{
	
public:
	int val;
	Node* next;

	Node(){
		val=0;
		this->next=NULL;
	}
	Node(int x){
		val=x;
		this->next=NULL;
	}
};

class List{
	

public:
	Node *head;
	List() {head=NULL;};
	void printlist();
	void append(int data);
	
};

void List::printlist(){
	Node* temp=head;
	if (temp==NULL) {
		cout<<"EMPTY"<<endl;
		return;
	}
	if (temp->next==NULL){
		cout<<temp->val;
		cout<<"-> ";
		cout<<"NULL"<<endl;
		return;
	}
	else {
		do {
			cout<<temp->val;
			cout<<"-> ";
			temp=temp->next;
		}
		while (temp!=NULL);
		cout << "NULL" << endl;
		
	}
}

void List::append(int x) {
	Node* newnode=new Node(x);
	Node* temp=head;
	if (temp!=NULL){
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
	else {
		head=newnode;
	}
}
