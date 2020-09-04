#include <iostream>
#include <stack>

using namespace std;

void place_at_bottom(int bottom,stack <int> &s){
    //base case
    if(s.empty()){
        s.push(bottom);
        return;
    }
    
    //recursive case
    int top=s.top();
    s.pop();
    place_at_bottom(bottom,s);
    s.push(top);
    return;
    
}

void rev_recursion(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    //recursive case
    int top=s.top();
    s.pop();
    rev_recursion(s);
    place_at_bottom(top,s);
}

int main()
{
    stack <int> s;
    for(int i=1;i<10;i++){
        s.push(i);
    }
    
    rev_recursion(s);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}
