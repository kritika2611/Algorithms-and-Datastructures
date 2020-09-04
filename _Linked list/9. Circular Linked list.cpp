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

void insert_at_head(node* &head,int data){
    node* new_node=new node(data);
    
    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }
    
    node*tail=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=new_node;
    new_node->next=head;
    head=new_node;
    return;
}

void insert_at_tail(node *&head,int data){
    node *new_node=new node(data);
    if(head==NULL){
        head=new_node;
        new_node->next=head;
        return;
    }
    
    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    return;
}

void delete_node(node *&head,int data){
    //finding the node with data
    if(head->data==data){
        node* temp=head;
        node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=head->next;
        head=temp->next;
        delete temp;
        return;
    }
    
    node* prev=NULL;
    node*del=head;
    
    while(del->next!=head){
        if(del->data==data){
            break;
        }
        prev=del;
        del=del->next;
    }
    //checking at end node
    if(del->data==data){
        prev->next=del->next;
        delete del;
    }
    else{
        cout<<"node not found"<<endl;
    }
    
}

void print(node* head){
    if(head==NULL){
        cout<<"The circular Linked list is empty"<<endl;
        return;
    }
    
    node* temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    
}

int main(){
    node* head=NULL;
    insert_at_head(head,10);
    insert_at_tail(head,23);
    insert_at_tail(head,69);
    insert_at_tail(head,70);
    insert_at_head(head,12);
    
    print(head);
    delete_node(head, 69);
    print(head);
    delete_node(head,56);
    
    return 0;
}