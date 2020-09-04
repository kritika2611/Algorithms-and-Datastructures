#include <bits/stdc++.h>
#include <queue>

using namespace std;

//approach 1
class my_stack1{
private:
    queue<int> q1;
    queue<int> q2;
    
public:
    bool empty(){
        return q1.empty() && q2.empty();
    }
    
    void push(int d){
        q1.push(d);
    }
    
    void pop(){
        if(empty()){
            cout<<"stack underloading"<<endl;
            return;
        }
        
    
        int n=q1.size()-1;
        while(n--){
            int f=q1.front();
            q2.push(f);
            q1.pop();
        }
        //removing last element
        q1.pop();
        
        //swapping names
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
    }
        
    
    int top(){
        int n=q1.size()-1;
        while(n--){
            int f=q1.front();
            q2.push(f);
            q1.pop();
        }
        int t=q1.front();
        q2.push(t);
        q1.pop();
        
        //swapping names
        queue <int> temp=q1;
        q1=q2;
        q2=temp;
        return t;
    }
    
};

//approach 2
class my_stack2{
private:
    queue <int> q1,q2;
    
public:
    bool empty(){
        return q1.empty() && q2.empty();
    }
    
    void push(int d){
        if(empty()){
            q1.push(d);
            return;
        }
        
        if(q1.empty()){
            q1.push(d);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        
        else if(q2.empty()){
            q2.push(d);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    void pop(){
        if(empty()){
            cout<<"Stack underloading"<<endl;
            return;
        }
        if(!q1.empty()){
            q1.pop();
        }
        else if(!q2.empty()){
            q2.pop();
        }
    }
    
    int top(){
        if(!q1.empty()){
            return q1.front();
        }
        return q2.front();
    }
    
};

int main()
{
    my_stack1 s;
    
    for(int i=1;i<=10;i++){
        s.push(i);
    }
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

