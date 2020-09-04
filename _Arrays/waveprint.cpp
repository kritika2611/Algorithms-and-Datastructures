#include <bits/stdc++.h>

using namespace std;

void wave_print(int r,int c,char mat[][10]){
	for(int cl=0; cl<c; cl++){
		for(int row=0; row<r; row++){
			if (cl%2==0)
				cout<<mat[row][cl];
			else
				cout<<mat[r-1-row][cl];
		}
	}
}

void read_mat(char mat[][10],int r,int c){
	for(int row=0;row<r;row++){
		for(int col=0;col<c;col++){
			cin>>mat[row][col];
		}
	}
}

int main(){
	int r,c;
	char mat[10][10];
	cout<<"enter the number of rows: ";
	cin >>r;

	cout<<"enter the number of columns: ";
	cin>>c;

	read_mat(mat,r,c);

	wave_print(r,c,mat);


	return 0;
}