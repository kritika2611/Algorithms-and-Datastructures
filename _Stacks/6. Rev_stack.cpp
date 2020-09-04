#include <iostream>
#include <stack>

using namespace std;

void rev(stack<int> &s){
    stack <int> help;
    int n=s.size();
    for(int i=1;i<n;i++){
        //save top element
        int top=s.top();
        s.pop();
        int rem=n-i;
        
        //shift all the elements to help stack
        int rem1=rem;
        while(rem1--){
            help.push(s.top());
            s.pop();
        }
        
        //place top element back
        s.push(top);
        
        //shift the elemenst back to s
        while(rem--){
            s.push(help.top());
            help.pop();
        }
        
    }
}

int main()
{
    stack <int> s;
    for(int i=1;i<=15;i=i+2){
        s.push(i);
    }
    
    rev(s);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
