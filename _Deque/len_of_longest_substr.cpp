#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[]="abcdaaxyzq";
    
    int curr_len=1;
    int max_len=INT_MIN;
    int last_occ[256];
    
    
    
    for(int i=0;i<256;i++){
        last_occ[i]=-1;
    }
    
    last_occ[s[0]]=0;
    int i=1;
    while(s[i]!='\0'){
        int l=last_occ[s[i]];
        
        if(l==-1 || i-curr_len>l){
            curr_len+=1;
        }
        else{
            curr_len=i-l;
        }
        
        max_len=max(max_len,curr_len);
        last_occ[s[i]]=i;
        i++;
    }
    
    cout<<max_len<<endl;

    return 0;
}
