#include <bits/stdc++.h>
#include <queue>

using namespace std;

/* FOUR METHODS
1. pop()
2. push()
3. front()
4. empty() */


int main(){
    
    queue<char> q;

    q.pop();
    for(char i=58;i<75;i++){
        q.push(i);
    }
    
    int n=5;
    while(n--){
        q.pop();
    }
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    

    return 0;
}