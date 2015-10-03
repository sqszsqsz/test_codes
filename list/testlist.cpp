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

	cout << "new list  ";
	solution A;
	List list1(list);
	list1.printlist();
	cout << "new list after reverse by iteration  " ;
	A.reverseiteration(list1.head);
	list1.printlist();

	cout << "new list  ";
	List list2(list);
	list2.printlist();
	cout << "new list after reverse by recursion  ";
	list2.head=A.reverserecursion(list2.head);
	list2.printlist();

	cout << "new list  ";
	List list3(list);
	list3.printlist();
	cout << "new list after reverse by iteration version2  ";
	A.reverse2(list3.head);
	list3.printlist();



	return 0;

	
}