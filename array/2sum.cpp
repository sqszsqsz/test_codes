#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printarray(int* p, int size){
	for (int i=0;i<size;i++){
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;

	return;
}

int twosum_norepeat(int* nums, int size, int target){
	if (size==0) return 0;
	map<int,int> m;
	int count=0;
	for (int i=0;i<size;i++){
		if (m.find(target-nums[i])!=m.end()){
			count++;
		}
		else (m[nums[i]]=i);
	}
	return count;
}

int twosum_repeat(int* nums, int size, int target){
	if (size==0) return 0;
	map<int,int> m;
	for (int i=0;i<size;i++) m[nums[i]]++;

	int count=0;

	for (int i=0;i<size;i++){
		if (m.find(target-nums[i])!=m.end()){
			count+=m[target-nums[i]];
		}
		
	}
	return count/2;
}


int main(){

	cout << "Input number of array elements" << endl;
	int n;
	cin>>n;
	int* array=new int[n];
	cout << "Input the array elements" << endl;

	for (int i=0;i<n;i++){
		cin>>array[i]; 
	}
	cout << "Input array is: " << endl;
	printarray(array,n);

	cout << "key in the target number"<<endl;
	int t;
	cin>>t;

	cout << "2 Sum numbers with no repeat is " << twosum_norepeat(array,n,t) << endl;

	cout << "2 Sum numbers with repeat is " << twosum_repeat(array,n,t) << endl;

	return 0;
}