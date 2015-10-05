#include <iostream>
#include <cstring>

using namespace std;


char* preprocess(char *s){
	int n=strlen(s);
	char *ret=new char[2*n+3];
	ret[0]='^';
	for (int i=1;i<=n;i++){
		ret[2*i-1]='#';
		ret[2*i]=s[i-1];
	}
	strcat(ret,"#\0");
	strcat(ret,"$\0");

	return ret;

}

char* palindrome(char * s){
	int len=strlen(s);
	char* t=preprocess(s);
	int n=strlen(t);
	// cout<<"n="<<n<<endl;
	int R=0,C=0;
	int p[n];
	for (int i=1;i<n-1;i++){
		int i_mirror=C-(i-C);
		if (R>i){
			p[i]=p[i_mirror]<R-i? p[i_mirror]:R-i;
		}
		else p[i]=0;
		while (t[i-1-p[i]]==t[i+1+p[i]]) p[i]++;
		if (i+p[i]>R){
			R=i+p[i];
			C=i;
		}
	}

	int maxlen=0,center=0;
	for (int i=1;i<n-1;i++){
		if (maxlen<p[i]){
			maxlen=p[i];
			center=i;
		}
	}

	char* ret= new char[maxlen+1];
	for (int j=0;j<maxlen;j++){
		ret[j]=s[j+(center-1-maxlen)/2];
	}
	ret[maxlen]='\0';


	return ret;
}

int main() {

	char input[256]="zxcvelleellejdklas";
	
	char* palindrome_string=palindrome(input);

	cout <<"longest palindrome substring is: "<< palindrome_string << endl;


	return 0;
}