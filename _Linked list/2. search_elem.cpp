#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node *next;

	//constructor
	node(int d){
		data=d;
	}
};

int len(node *head){
	int l=0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}

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

void insert_at_mid(node *&head,int data,int p){
	if(head==NULL || p==0){
		insert_at_head(head,data);
		return;
	}
	if(p>len(head)){
		insert_at_tail(head,data);
		return;
	}

	int jump=1;
	node *temp=head;
	while(jump<=p-1){
		temp=temp->next;
		jump++;
	}
	node *n=new node(data);
	n->next=temp->next;
	temp->next=n;
}

int search_key_recursive(node *head,int key){
	//base case
	if(head==NULL){
		return -1;
	}

	//recursive case
	if(head->data==key){
		return 0;
	}

	int next_=search_key_recursive(head->next,key);
	if(next_==-1){
		return -1;
	}
	return 1+next_;

}

int search_key_iterative(node *head,int key){
	int i=0;
	while(head!=NULL){
		if(head->data==key){
			return i;
		}
		i++;
		head=head->next;
	}
	return -1;
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head=head->next;
	}
	cout<<endl;
}


int main(){

    node *head=NULL;
    insert_at_head(head,6);
    insert_at_head(head,3);
    insert_at_head(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,9);
    insert_at_mid(head,5,3);
    insert_at_tail(head,10);

    print(head);
    
    int idx=search_key_recursive(head,8);
    if(idx==-1)
    	cout<<"8 is not present"<<endl;
    else
    	cout<<"8 is present at "<<idx<<endl;

    int idx2=search_key_iterative(head,14);
    if(idx2==-1)
    	cout<<"14 is not present"<<endl;
    else
    	cout<<"14 is present at "<<idx2<<endl;



	return 0;
}