#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void rotate_(int N,int **arr){
    //reverse row
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N/2;j++){
            swap(arr[i][j],arr[i][N-j-1]);
        }
    }
    //transpose
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    
}

void rotate_stl(int N,int **arr){
    cout<<endl;
    for(int i=0;i<N;i++)
        reverse(arr[i],arr[i]+N);
        
    //transpose
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main(){
    int N;
    cin>>N;
    int **arr=new int*[N];
    for(int i=0;i<N;i++)
        arr[i]=new int [N];
        
    int val=1;    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=val;
            val++;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    rotate_stl(N,arr);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
