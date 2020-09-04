#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* next;
    
    //constructor
    node(int data){
       this->data=data; 
       this->next=NULL;
    }
};

class my_stack{
private:
    node*ptr=NULL;
    
public:
    //constructor
    my_stack(){
        //
    }
    
    void push(int data){
        node* new_node=new node(data);
        new_node->next=this->ptr;
        this->ptr=new_node;
    }
    
    void pop(){
        if(ptr==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        node*temp=this->ptr;
        this->ptr=temp->next;
        delete temp;
    }
    
    int top(){
        return this->ptr->data;
    }
    
    bool isEmpty(){
        return this->ptr==NULL;
    }
    
    
};

int main()
{
    my_stack s;
    if(s.isEmpty()){
       cout<<"stack is empty"<<endl; 
    }
    s.push(10);
    s.push(12);
    s.push(14);
    s.pop();
    cout<<s.top()<<endl;
    s.push(8);
    s.push(6);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    return 0;
}
