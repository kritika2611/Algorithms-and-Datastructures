#include <bits/stdc++.h>

using namespace std;

bool Is_safe(int i,int j,int board[][10],int n){
    //checking along the column
    for(int x=0;x<n;x++){
        if(board[x][j]==1)
            return false;
    }
    //checking diagonals
    int d=i-j;
    int s=i+j;
    
    for(int x=0;x<n;x++){
        int y=x-d;
        if(y<0 || y>=n){
            continue;
        }
        else if(board[x][y]==1){
            return false;
        }
    }
    
    for(int x=0;x<n;x++){
        int y=s-x;
        if(y<0 || y>=n){   //outside board
            continue;
        }
        else if(board[x][y]==1){
            return false;
        }
    }
    
    return true;
    
}

bool n_queen(int board[][10],int n,int i){
    //base case
    if(i==n){
        //print board
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(board[j][k]==1)
                    cout<<"Q"<<" ";
                else
                    cout<<"-"<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    
    //recursive case
    for(int j=0;j<n;j++){
        if(Is_safe(i,j,board,n)){
            board[i][j]=1;
            n_queen(board,n,i+1);
            board[i][j]=0;     //backtracking
        }
    }
    
    return false;
}

int main(){
    int n;
    cin>>n;
    int board[10][10]={0};
    bool val=n_queen(board,n,0);
    return 0;
}