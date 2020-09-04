#include <bits/stdc++.h>

using namespace std;

bool feasible_cell(int mat[][10],int i,int j,int r,int c){
	if(mat[i][j]!=0 && i<r && j<c)
		return true;

	return false;
}

int rat_in_maze(int i,int j,int r,int c,int mat[][10]){
	//base case
	if(i==r-1 && j==c-1){
		return 1;
	}

	//right
	int right=0,down=0;
	if(feasible_cell(mat,i,j+1,r,c)){
		right=rat_in_maze(i,j+1,r,c,mat);
	}
	if(feasible_cell(mat,i+1,j,r,c)){
		down=rat_in_maze(i+1,j,r,c,mat);
	}
	return right+down;
}

int main(){
	int r,c;
	cin>>r>>c;
	int mat[10][10];

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];
	cout<<endl;

	int paths=rat_in_maze(0,0,r,c,mat);
	cout<<paths;
	return 0;
}