#include <bits/stdc++.h>

using namespace std;

void gen_brackets(char *arr,int i,int N,int o,int c){
    //base case
    if(c==N){
        arr[i]='\0';
        cout<<arr<<endl;
        return;
    }
    
    //recursive case
    if(o<N){
        arr[i]='(';
        gen_brackets(arr,i+1,N,o+1,c);
    }
    if(c<o){
        arr[i]=')';
        gen_brackets(arr,i+1,N,o,c+1);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    char arr[1000];
    gen_brackets(arr,0,n,0,0);
    
    return 0;
}
