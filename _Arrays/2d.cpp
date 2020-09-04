#include <bits/stdc++.h>
using namespace std;

void subarr_sum(int r, int c, int **arr){
	int tl,br;
	int cont=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tl=(i+1)*(j+1);
			br=(r-i)*(c-j);
			cont+=arr[i][j]*tl*br;
		}
	}
	cout<<cont;
}


int main(){
	int r,c;
	cin>>r>>c;

	int **arr=new int *[r];
	for(int i=0;i<r;i++){
		arr[i]=new int [c];
	}

	//input array
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}

	subarr_sum(r,c,arr);

	return 0;
}