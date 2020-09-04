#include <bits/stdc++.h>

using namespace std;

class node{
public:
  int data;
  node*next;
  
  node(int d){
      data=d;
  }
};

int len(node *head){
    int i=0;
    while(head!=NULL){
        i++;
        head=head->next;
    }
    return i;
}

void insert_at_head(node *&head,int data){
    node *new_node=new node(data);
    new_node->next=head;
    head=new_node;
}

void insert_at_tail(node *&head,int data){
    if(head==NULL){
        insert_at_head(head,data);
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        node *new_node=new node(data);
        temp->next=new_node;
        new_node->next=NULL;
        
    }
}

void insert_at_mid(node *&head,int data,int p){
    if(head==NULL || p==0){
        insert_at_head(head,data);
    }
    else if(p>len(head)){
        insert_at_tail(head,data);
    }
    else{
        int jump=1;
        node *temp=head;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
        }
        
        node *new_node=new node(data);
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void delete_at_head(node *&head){
    if(head==NULL){
        return;
    }
    node *temp=head;
    head=head->next;
    delete temp;
    return;
}

void delete_at_tail(node *&head){
    if(len(head)==1){
        delete_at_head(head);
        return;
    }

    node *prev=NULL;
    node *temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
    return;

}

void delete_at_mid(node *&head,int p){
    if(p==0){
        delete_at_head(head);
        return;
    }
    node *prev=NULL;
    node *temp=head;
    while(p){
        prev=temp;
        temp=temp->next;
        p--;
    }
    prev->next=temp->next;
    delete temp;
    return;
}

void print_linkedlist(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node *head=NULL;
    insert_at_head(head,6);
    insert_at_head(head,3);
    insert_at_head(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,9);
    insert_at_mid(head,5,3);
    insert_at_tail(head,10);
    
    delete_at_head(head);
    delete_at_tail(head);
    delete_at_mid(head,2);
    
    print_linkedlist(head);
    cout<<len(head)<<endl;

    return 0;
}
