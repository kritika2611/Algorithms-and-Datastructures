#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> lotterynum(0);        //vector declaration
	int arr[5]={1,2,3,4,5};       //array
	cout<<"size of vector before inserting: "<<lotterynum.size()<<endl;
	lotterynum.insert(lotterynum.begin(),arr,arr+4);     //inserting values in a vector
	cout<<lotterynum.at(3)<<endl;	
	cout<<lotterynum.back()<<endl;
	cout<<"size of vector: "<<lotterynum.size()<<endl;

	return 0;
}