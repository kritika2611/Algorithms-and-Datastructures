#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue <char> q;
    int freq[27]={0};
    
    //taking input stream
    char ch;
    cin>>ch;
    while(ch!='.'){
       //logic
       q.push(ch);
       int idx=ch-'a';
       freq[idx]+=1;
       
       //query
       int i=q.front()-'a';
       
       while(freq[i]>1 && !q.empty()){
           q.pop();
           i=q.front()-'a';
       }
       
       if(q.empty()){
           cout<<"-1"<<" ";
       }
       else{
           cout<<q.front()<<" ";
       }
       
       cin>>ch;
    }

    return 0;
}
