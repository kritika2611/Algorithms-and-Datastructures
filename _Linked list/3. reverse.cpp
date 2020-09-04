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

void rev_iterative(node *&head){
   node*prev=NULL;
   node*curr=head;
   while(curr!=NULL){
       //saving next node
       node *next=curr->next;
       //reversing the link
       curr->next=prev;
       //updating
       prev=curr;
       curr=next;
   }
   head=prev;
}

node* rev_recursive(node *curr){
    //base case
    if(curr->next==NULL || curr==NULL){
        return curr;
    }
    
    //recursive case
    node *head=rev_recursive(curr->next);
    curr->next->next=curr;
    curr->next=NULL;
    return head;
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
    
    rev_iterative(head);
    print(head);
    
    head=rev_recursive(head);
    print(head);

    return 0;
}
