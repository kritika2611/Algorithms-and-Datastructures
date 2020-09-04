/**********************************************************************************************************************************************
INPUT= 8 5 15 4 7 13 3 5 6 11 14 9 12 -1

OUTPUT= 3 4 5 5 6 7 8 9 11 12 13 14 15
*********************************************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};

node* insert_node(node* root,int d){
    //base case
    if(root==NULL){
        node* n=new node(d);
        return n;
    }

    if(d<=root->data) root->left=insert_node(root->left,d);
    else root->right=insert_node(root->right,d);

    return root;
}

node* Build(){
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1){
        root=insert_node(root,d);
        cin>>d;
    }
    return root;
}

class Pair_{
public:
    node *head;
    node *tail;
};

Pair_ BST_2_LL(node *root){
    //Base case--leaf node
    Pair_ p;
    if(root->left==NULL && root->right==NULL){
        p.head=root;
        p.tail=root;
        return p;
    }

    //Recursive case
    if(root->left==NULL){
        Pair_ r=BST_2_LL(root->right);
        root->right=r.head;
        p.head=root;
        p.tail=r.tail;
        return p;
    }
    if(root->right==NULL){
        Pair_ l=BST_2_LL(root->left);
        root->left=root->right=NULL;
        l.tail->right=root;
        p.tail=root;
        p.head=l.head;
        return p;
    }
    Pair_ l=BST_2_LL(root->left);
    Pair_ r=BST_2_LL(root->right);
    root->left=root->right=NULL;
    l.tail->right=root;
    root->right=r.head;
    p.head=l.head;
    p.tail=r.tail;
    return p;
}

void Print_LL(node* head){
    if(head==NULL) return;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}

int main(){
    node* root=Build();
    Pair_ p=BST_2_LL(root);
    Print_LL(p.head);
    return 0;
}