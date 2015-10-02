#include <iostream>
#include "listclass.h"
#include "solution.h"
#include <vector>

/*void printvector(vector<int> v){
	for (size_t i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<endl;
}*/




int main() {
	
	cout << "Enter the number of nodes"<<endl;
	int n;
	cin>>n;
	cout << "Key in entries for linked list" << endl;
	vector<int> input;
	int value;

	List list;

	for (int i=0;i<n;i++){
		cin>>value;
		list.append(value);
	
	}
	list.printlist();

	cout << "new list after reverse by iteration" << endl;
	solution A;
	A.reverseiteration(list.head);
	
	list.printlist();

	cout << "new list after reverse by recursion" << endl;

	list.head=A.reverserecursion(list.head);
	list.printlist();



	return 0;

	
}