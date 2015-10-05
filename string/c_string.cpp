#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int main() {

	int len=10;
	char* test= new char[len];
	int* p=new int[len];

	for (int i=0;i<10;i++){
		test[i]='a';
		p[i]=i+1;
	}
	test[len]='\0';


	cout<<"test string is: ";
	for (int i=0;i<11;i++){
		cout<<test[i];
	}
	cout<<endl;

	cout<<"test array is: ";
	for (int i=0;i<10;i++){
		cout << p[i];
	}
	cout<<endl;

	char* ret=new char[5];
	for (int i=3;i<3+4;i++){
		ret[i-3]=test[i];
	}

	ret[4]='\0';
	cout<<ret<<endl;
	
	return 0;
}