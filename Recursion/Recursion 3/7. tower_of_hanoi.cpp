#include <bits/stdc++.h>

using namespace std;

int move(int n,char s,char d,char h){
	//base case
	if(n==1){
		cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
		return 1;
	}

	//recursive case
	int x=move(n-1,s,h,d);
	cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
	int y=move(n-1,h,d,s);
	return x+y+1;
}

int main(){
	int n;
	cin>>n;
	int steps=move(n,'A','C','B');
	cout<<"Total steps taken are: "<<steps;

	return 0;
}