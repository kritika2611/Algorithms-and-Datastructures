#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,M,K,S;
    cin>>N>>M>>K>>S;
    char arr[1000][1000];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        cin>>arr[i][j];
    }
    
    bool flag=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='.')
                S=S-2;
            else if(arr[i][j]=='*')
                S=S+5;
            else if(arr[i][j]=='#')
                break;
            
            if(j!=M-1)
                S--;
        }
        if(S<K){
            flag=false;
            break;
        }
    }
    if(flag==true){
        cout<<"YES"<<endl;
        cout<<S;    
    }
    else
        cout<<"NO";
    
    
    return 0;
}
