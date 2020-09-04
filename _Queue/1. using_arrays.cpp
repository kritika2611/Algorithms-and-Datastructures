#include <bits/stdc++.h>

using namespace std;

class my_queue{
private:
    int *arr;
    int f,r,cs,ms;
    
public:
    my_queue(int size=10){
       this->arr=new int[size];
       this->cs=0;
       this->ms=size;
       this->f=0;
       this->r=size-1;
    }
    
    bool empty(){
        return cs==0;
    }
    
    bool full(){
        return cs==ms;
    }
    
    void push(int d){
        
        if(full()){
            cout<<"The queue is full"<<endl;
            return;
        }
        
        //increment rear
        r=(r>=ms-1)?((r+1)%ms):r+1;
        
        //add the element
        arr[r]=d;
        cs+=1;
    }
    
    void pop(){
        if(empty()){
            cout<<"The queue is empty"<<endl;
            return;
        }
        
        //increment front
        f=(f>=ms-1)?((f+1)%ms):f+1;
        cs-=1;
    }
    
    int front(){
        return arr[f];
    }
    
};

int main()
{
    my_queue q(10);
    q.pop();
    for(int i=1;i<15;i++){
        q.push(i);
    }
    
    int n=5;
    while(n--){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    
    for(int i=15;i<20;i++){
        q.push(i);
    }
    
    //printing whole queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    
    
    

    return 0;
}
