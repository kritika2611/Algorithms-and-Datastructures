#include <bits/stdc++.h>

using namespace std;

void gen_subset(int n,string s){
	//generate numbers
	int max_num=pow(2,n);
	for(int i=0;i<max_num;i++){
		int j=0;
		int num=i;
		while(num>0){
			if(num&1)
				cout<<s[j];
			j=j+1;
			num=num>>1;
		}
		if(i!=max_num-1)
			cout<<endl;
	}
	
}

int main(){
	string str;
	getline(cin,str);
	int N=str.length();
	gen_subset(N,str);

	return 0;
}