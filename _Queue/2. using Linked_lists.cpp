#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    } 
};

class my_queue{
private:
    node* f=NULL;
    node* r=NULL;
    
public:
    my_queue(){
        
    }
    
    bool empty(){
        return f==NULL;
    }
    
    //pushing at rear end
    void push(int d){
        if(f==NULL){
            node *n=new node(d);
            n->next=NULL;
            f=n;
            r=n;
            return;
        }
        
        node *n=new node(d);
        r->next=n;
        r=n;
    }
    
    //poping from front
    void pop(){
        if(f==NULL){
            cout<<"Queue underloading"<<endl;
            return;
        }
        
        node *temp=f;
        f=temp->next;
        delete temp;
    }
    
    int front(){
        return f->data;
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
