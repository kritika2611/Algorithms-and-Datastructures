#include <bits/stdc++.h>
using namespace std;

void func(int r,int c,int **mat){
	//row wise
	for(int i=r-2;i>=0;i--){
		for(int j=c-1;j>=0;j--){
			mat[i][j]+=mat[i+1][j];
		}
	}
	//column wise
	for(int j=c-2;j>=0;j--){
		for(int i=r-1;i>=0;i--){
			mat[i][j]+=mat[i][j+1];
		}
	}
	int ans=INT_MIN;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			ans=(ans<mat[i][j])?mat[i][j]:ans;
		}
	}
	cout<<ans;
}


int main(){
	int r,c;
	cin>>r>>c;
	//define matrix
	int **mat=new int*[r];
	for(int i=0;i<r;i++){
		mat[i]=new int[c];
	}
	//input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	func(r,c,mat);
	return 0;
}