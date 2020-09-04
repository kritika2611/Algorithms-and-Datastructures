/***********************************    UNIQUE 2   *************************************************************
ALL the numbers in an array are occuring twice eexcept 2 numbers. Find the unique numbers

Example a=[1,1,2,3,5,2,5,7]
unique=3,7
****************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int get_setbit(int n){
	int i=0;
	while(n>0){
		int l_bit=n&1;
		if(l_bit==1)
			return i;
		i++;
		n=n>>1;
	}
	return -1;
}

int get_num(int arr[],int n, int set_bit){
    int mask=1<<set_bit;
    int ans=0;
    for(int i=0;i<n;i++){
        if((arr[i]&mask)>0){
            ans=ans^arr[i];
        }
    }
    return ans;
}

int main(){
	int arr[]={1,1,2,2,5,3,5,6};
	int n=sizeof(arr)/sizeof(int);
	int result=0;
	for(int i=0;i<n;i++)
		result=result^arr[i];
	
	int set_b=get_setbit(result);
	cout<<get_num(arr,n,set_b)<<endl;
	int a2=get_num(arr,n,set_b)^result;
	cout<<a2;

	return 0;
}