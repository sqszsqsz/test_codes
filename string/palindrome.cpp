#include <iostream>
#include <string>
using namespace std;

string preprocess(string s){
	int n=s.length();
	if (n==0) return "^$";
	string ret="^";

	for (int i=0;i<n;i++){
		ret+="#"+s.substr(i,1);
	}
	ret+="#$";
	return ret;

}

string longestpalindrome(string s){
	string T=preprocess(s);
	int n=T.length();
	int *p=new int[n];
	int C=0,R=0;
	for (int i=1;i<n-1;i++){
		int i_mirror=C-(i-C);
		if (R>i){
			p[i]=min(R-i,p[i_mirror]);
		}
		else {
			p[i]=0;
		}
		while (T[i-1-p[i]]==T[i+1+p[i]]) p[i]++;
		if (i+p[i]>R){
			C=i;
			R=C+p[i];
		}
	}
	int maxlen=0,centerindex=0;
	for (int j=1;j<n-1;j++){
		if (p[j]>maxlen){
			maxlen=p[j];
			centerindex=j;
		}
	}
	delete[] p;
	return s.substr((centerindex-1-maxlen)/2,maxlen);
}

int main(){
	string test;
	cout<<"Please input test string "<<endl;
	cin>>test;
	string output=preprocess(test);
	cout<<"preprocessed string is "<<output<<endl;
	cout<<endl;
	cout<<"longest palindromic substring is "<<longestpalindrome(test)<<endl;


	return 0;
}