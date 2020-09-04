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

node* detect_cycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}

void remove_cycle(node* head,node *common){
    node* slow=head;
    node* fast=common;
    //finding start point of the cycle
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    node*start=slow;
    while(slow->next!=start){
        slow=slow->next;
    }
    slow->next=NULL;
}



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
    
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head->next->next;
    
    node* common=detect_cycle(head);
    if(common!=NULL)
        cout<<"cycle detected"<<endl;
    else
        cout<<"there is no cycle"<<endl;
        
    //remove cycle
    if(common!=NULL){
        remove_cycle(head,common);
    }
    print(head);
    
    return 0;
}
