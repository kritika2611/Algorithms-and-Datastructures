#include <bits/stdc++.h>

using namespace std;

class my_stack{
private:
    vector<int>v;
    
public:
    //constructor
    my_stack(){
        
    }
    
    void push(int data){
        v.push_back(data);
    }
    
    bool Isempty(){
        return v.size()==0;
    }
    
    void pop(){
        if(this->Isempty()){
            cout<<"stack underloading"<<endl;
            return;
        }
        v.pop_back();
    }
    
    int top(){
        return v[v.size()-1];
    }
};

int main()
{
    my_stack s;
    if(s.Isempty()){
       cout<<"stack is empty"<<endl; 
    }
    
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    
    while(!s.Isempty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}
