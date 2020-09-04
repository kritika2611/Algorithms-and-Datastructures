#include <bits/stdc++.h>

using namespace std;

int main(){
	char max_ch;
	int count=0;
	int max_count=0; 
	
	//input string and sort it
	string s;
	getline(cin,s);
	int n=s.length();
	sort(s.begin(),s.end());

	//finding max_char
	int i=0;
	cout<<s[i]<<": ";
	int j;

	for(j=0;j<n;j++){
		if(s[i]!=s[j]){
			count=j-i;
			cout<<count<<endl;
			
			if(count>max_count){
				max_count=count;
				max_ch=s[i];
			}

			i=j;
			cout<<s[i]<<": ";	
		}

	}

	count=j-i;
	cout<<count<<endl;
	if(count>max_count){
		max_count=count;
		max_ch=s[i];
	}

	cout<<max_ch;

	return 0;
}