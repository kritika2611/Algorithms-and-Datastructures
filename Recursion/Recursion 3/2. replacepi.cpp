#include <bits/stdc++.h>

using namespace std;

void replace_pi(char *s,int i){
	//base case
	if(s[i]=='\0')
		return;
	
	//recursive call
	if(s[i]=='p' && s[i+1]=='i'){
		int j=i+2;

		while(s[j]!='\0')
			j++;

		//shifting
		for(;j>=i+2;j--){
			s[j+2]=s[j];
		}
		s[i]='3';
		s[i+1]='.';
		s[i+2]='1';
		s[i+3]='4';

		//recursion
		replace_pi(s,i+4);
	}
	else
		replace_pi(s,i+1);

}

int main(){
	char s[10000];
	cin.getline(s,10000);
	int n=strlen(s);
	replace_pi(s,0);
	cout<<s;
	return 0;
}