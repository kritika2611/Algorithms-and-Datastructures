#include <bits/stdc++.h>

using namespace std;

bool Can_place(int mat[][9],int i,int j,int num){
    //checking col
    for(int x=0;x<9;x++){
        if(mat[x][j]==num)
            return false;
    }
    //checking row
    for(int y=0;y<9;y++){
        if(mat[i][y]==num)
            return false;
    }
    //checking subgrid
    int p=i/3;
    int q=j/3;
    int sr=p*3,er=(p+1)*3;
    int sc=q*3,ec=(q+1)*3;
    for(int x=sr;x<er;x++){
        for(int y=sc;y<ec;y++){
            if(mat[x][y]==num)
                return false;
        }
    }
    return true;
}

bool Sudoku_solver(int mat[][9],int i,int j){
    //base case
    if(i==9){
        //print
        for(int x=0;x<9;x++){
            if(x!=0 && x%3==0)
                cout<<"- - - - - - - - - - -"<<endl;
            for(int y=0;y<9;y++){
                if(y!=0 && y%3==0){
                    cout<<"| ";
                }
                cout<<mat[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //if j reaches end of row
    if(j==9)
        return Sudoku_solver(mat,i+1,0);
    
    //recursive case
    if(mat[i][j]==0){
        for(int num=1;num<=9;num++){
            if(Can_place(mat,i,j,num)){
                mat[i][j]=num;
                bool sol=Sudoku_solver(mat,i,j+1);
                if(sol)
                    return true;
            }
        }  
        //no number gives the sol
        //backtrack
        mat[i][j]=0;
        return false;
    }
    else{
        //skip the element
        return Sudoku_solver(mat,i,j+1);
    }
}


int main(){
    int mat[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>mat[i][j];
    }
    cout<<endl;
    Sudoku_solver(mat,0,0);
    
}