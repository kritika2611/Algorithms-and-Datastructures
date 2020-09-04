#include <bits/stdc++.h>

using namespace std;

void print_subsets(char *in,char *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    
    //exclude current element
    print_subsets(in,out,i+1,j);
    //include current element
    out[j]=in[i];
    print_subsets(in,out,i+1,j+1);
    
}

int main()
{
    char in[1000];
    cin>>in;
    char out[1000];
    print_subsets(in,out,0,0);
    
    return 0;
}
