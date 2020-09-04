#include <bits/stdc++.h>

using namespace std;

void write_mat(int row, int col, int mat[][10]){
	int value=1;
	for(int r=0; r<row;r++){
		for(int c=0; c<col; c++){
			mat[r][c]=value++;
		}
	}
}

void print_mat(int row, int col, int mat[10][10]){
	cout<<endl;
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++){
			cout<<mat[r][c]<< " ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void SpiralPrint(int row,int col, int mat[][10]){
	cout<<"The spiral print of the matrix is: "<<endl;
	int startrow=0, endrow=row-1;
	int startcol=0, endcol=col-1;
	while (startrow<=endrow && startcol<=endcol){
		//print start row
		for(int j=startcol; j<=endcol; j++){
			cout<<mat[startrow][j]<<" ";
		}
		startrow++;

		//print end column
		for(int i=startrow;i<=endrow;i++){
			cout<<mat[i][endcol]<<" ";
		}
		endcol--;

		//print endrow
		if(startrow<endrow){
		for(int j=endcol;j>=startcol;j--){
			cout<<mat[endrow][j]<<" ";
		}
		endrow--;
	    }

		//print start col
		if (startcol<endcol){
		for(int i=endrow; i>=startrow;i--){
			cout<<mat[i][startcol]<<" ";
		}
		startcol++;
		}
	}
	cout<<endl;
}

int main(){
	int row ,col;
	cin>>row>>col;
	int mat[10][10];

	write_mat(row,col,mat);
	print_mat(row,col,mat);
	SpiralPrint(row,col,mat);

	return 0;
}