#include <bits/stdc++.h>

using namespace std;

template <typename T, typename U>

class my_stack{
private:
    vector<T>v;
    vector<U>v2;
public:
    //constructor
    my_stack(){
        
    }
    
    void push(T data){
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
    
    T top(){
        return v[v.size()-1];
    }
};

int main()
{
    my_stack <int,char> s;
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
