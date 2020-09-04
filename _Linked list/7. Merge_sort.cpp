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

/*************************************************************************/

node* merge_recursive(node* head1,node* head2){
    //base case
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    //recursive case
    node* c;
    if(head1->data < head2->data){
        c=head1;
        c->next=merge_recursive(head1->next,head2);
    }
    else{
        c=head2;
        c->next=merge_recursive(head1,head2->next);
    }
    return c;
}

node* merge_sort(node* head){
    //base case
    if(head->next==NULL || head==NULL){
        return head;
    }
    
    //recursive case
    // 1. split Linked list
    node* fast=head->next;
    node* mid=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        mid=mid->next;
    }
    
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;
    
    node *a_sorted=merge_sort(a);
    node *b_sorted=merge_sort(b);
    
    //merging the two sorted Linked lists
    node *merge=merge_recursive(a_sorted,b_sorted);
    return merge;
}

/*****************************************************************************/


void input_LL(node *&head){
    int data;
    cin>>data;
    
    while(data!=-1){
        insert_at_tail(head,data);
        cin>>data;
    }
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
    input_LL(head);
    print(head);
    
    node* merge=merge_sort(head);
    print(merge);

    
    return 0;
}
