#include <bits/stdc++.h>

using namespace std;

bool isodd(int n){
	return (n&1);
}

int get_bit(int n,int i){
	//create a mask
	int mask=1<<i;
	if((n & mask) >0)
		return 1;
	else
		return 0;
}

int set_bit(int n,int i){
	//use mask and or it with the number
	int mask=1<<i;
	int ans=mask | n;
	return ans;
}
 int clear_bit(int n,int i){
 	// and it with 0 at the location i
 	int mask=1<<i;
 	mask=~mask;
 	int ans=mask & n;
 	return ans;
 }

 int update_bit(int n, int i, int v){
 	//clear bit at ith position
 	int m1=~(1<<i);
 	n=n&m1; //ith bit cleared

 	//or the bit with v
 	int m2=v<<i;
 	n=n|m2;
 	return n;
 }

 int clear_last_i_bits(int n,int i){
 	// -1 has all ones in binary form
 	int mask=(-1<<i);     //gives i zeroes at the end
 	int ans=n&mask;
 	return ans;
 }

 int clear_range(int n,int s,int e){
 	int m1=-1<<(e+1);
 	int m2=~(-1<<s);      //  pow(2,s)-1
 	int m=m1|m2;

 	return n&m;
 }


int main(){
	int n,i;
	cin>>n>>i;

	if(isodd(n))
		cout<<"the number is odd"<<endl;
	else
		cout<<"the number is even"<<endl;

	cout<<"Bit "<<i<< " is "<<get_bit(n,i)<<endl;

	cout<<set_bit(n,i)<<endl;
	cout<<clear_bit(n,i)<<endl;

	cout<<"enter the value: ";
	int v;
	cin>>v;


	
	cout<<update_bit(n,i,v)<<endl;

	cout<<clear_last_i_bits(n,i)<<endl;

	cout<<"add start and end value: ";
	int s,e;
	cin>>s>>e;
	cout<<clear_range(n,s,e)<<endl;

	return 0;
}