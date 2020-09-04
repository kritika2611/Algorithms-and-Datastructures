#include<bits/stdc++.h>
using namespace std;

void search_key(int key,int row,int col,int mat[][50]){
	int x=row-1,y=0;

	while(x>=0 && y<col){
		if (mat[x][y]==key){
			cout<<endl<<"Key is found at position: "<<x<<" "<<y<<endl;
			return;
		}
		else if(mat[x][y]<key){
			y++;
		}
		else{
			x--;
		}
	}
	cout<<endl<<"Key not found :("<<endl;
	return;

}


int main(){
	int row,col,key;
	int mat[50][50];

	cin>>row>>col;      //taking the number of rows and columns
	for(int r=0;r<row;r++){
		for(int c=0;c<col;c++){
			cin>>mat[r][c];
		}
	}

	cin>>key;
	search_key(key,row,col,mat);

	return 0;
}