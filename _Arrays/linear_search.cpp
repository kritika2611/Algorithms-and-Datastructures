#include <bits/stdc++.h>

using namespace std;

int LinearSearch(int key, int arr[10]){
	int val=-1;
	for(int i=0;i<=9;i++){
		if (key==arr[i]) {
			val=i;
			break;
		}
		else
			continue;
	}
	return val;
}


int main(){
	int arr[10];
	int key=2;
	//input the array
	cout<<"enter ten integers:"<<endl;
	for(int i=0;i<=9;i++){
		cin>>arr[i];
	}
	int index=LinearSearch(key,arr);
	cout<<"2 is found at index: "<<index<<endl;
	return 0;
}