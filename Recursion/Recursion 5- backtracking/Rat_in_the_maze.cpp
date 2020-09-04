#include <bits/stdc++.h>

using namespace std;

bool feasible_move(int mat[][10],int i,int j,int r,int c){
	if(mat[i][j]!=0 && i<r && j<c)
		return true;

	return false;
}

void rat_in_maze(int i,int j,int r,int c,int mat[][10],int sol[][10]){
	//base case
	if(i==r-1 && j==c-1){
		sol[i][j]=1;

		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	cout<<endl;
	sol[i][j]=0;
	return;
	}


	sol[i][j]=1;
	//right
	if(feasible_move(mat,i,j+1,r,c)){
		rat_in_maze(i,j+1,r,c,mat,sol);
		sol[i][j+1]=0;
	}

	//down
	if(feasible_move(mat,i+1,j,r,c)){
		rat_in_maze(i+1,j,r,c,mat,sol);
		sol[i+1][j]=0;
	}
	sol[i][j]=0;

	return;
}

int main(){
	int r,c;
	cin>>r>>c;
	int mat[10][10];

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>mat[i][j];
	cout<<endl;
	int sol[10][10]={0};

	rat_in_maze(0,0,r,c,mat,sol);
	return 0;
}