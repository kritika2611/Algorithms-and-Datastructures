#include <bits/stdc++.h>

using namespace std;

class my_queue{
private:
    stack <int> s1;
    stack <int> s2;
    
public:
    bool empty(){
        return s1.empty() && s2.empty();
    }
    
    void push(int d){
        s1.push(d);
    }
    
    void pop(){
        if(empty()){
            cout<<"Queue underflow"<<endl;
            return;
        }
        
        int n=s1.size()-1;
        while(n--){
            s2.push(s1.top());
            s1.pop();
        }
        //remove element
        s1.pop();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int front(){
        int n=s1.size()-1;
        while(n--){
            s2.push(s1.top());
            s1.pop();
        }
    
        int element=s1.top();
        s2.push(element);
        s1.pop();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        return element;
    }
};

int main(){
    my_queue q;
    
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}