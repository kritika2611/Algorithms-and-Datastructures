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

node* merge_two_LL(node* head1, node* head2){
    node* head=NULL;
    node* i=head1;
    node* j=head2;
    
    while(i!=NULL && j!=NULL){
        if(i->data <= j->data){
            insert_at_tail(head,i->data);
            i=i->next;
        }
        else{
            insert_at_tail(head,j->data);
            j=j->next;
        }
    }
    
    while(i!=NULL){
        insert_at_tail(head,i->data);
        i=i->next;
    }
    
    while(j!=NULL){
        insert_at_tail(head,j->data);
        j=j->next;
    }
    
    return head;
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
    node *head1=NULL;
    node *head2=NULL;
    //taking inputs
    input_LL(head1);
    input_LL(head2);
    
    node* merge=merge_recursive(head1,head2);
    print(merge);
    
    return 0;
}
