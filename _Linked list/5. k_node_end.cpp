#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node *next;
    
    node(int d){
        data=d;
    }
};

void insert_at_head(node *&head,int data){
    node *new_node=new node(data);
    new_node->next=head;
    head=new_node;
}

void insert_at_tail(node *&head,int data){
    if(head==NULL){
        insert_at_head(head,data);
        return;
    }

    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    node *n=new node(data);
    temp->next=n;
    n->next=NULL;
}

node* k_node_from_end(node* head, int k){
    node *fast=head;
    node *slow=head;
    //moving fast k steps insert_at_head
    while(k--){
        fast=fast->next;
    }
    
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node *head=NULL;
    //taking inputs
    int n;
    cin>>n;
    
    int data;
    while(n--){
        cin>>data;
        insert_at_tail(head,data);
    }
    
    print(head);
    int k;
    cin>>k;
    
    node* k=k_node_from_end(head,k);
    cout<<k->data;
    return 0;
}
