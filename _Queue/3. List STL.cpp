#include <bits/stdc++.h>
#include <list>

using namespace std;

class my_queue{
private:
    list <int> l;
    
public:
    my_queue(){
        
    }
    
    bool empty(){
        return l.empty();
    }
    
    void push(int d){
        l.push_back(d);
    }
    
    void pop(){
        if(empty()){
            cout<<"Queue underloading"<<endl;
            return;
        }
        l.pop_front();
    }
    
    int front(){
        return l.front();
    }
};

int main(){
    
    my_queue q;

    q.pop();
    for(int i=1;i<15;i++){
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