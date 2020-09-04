/************************************************************************************************
INPUT:
8 10 1 -1 -1 6 4 -1 -1 17 -1 -1 3 -1 14 13 -1 -1 -1

           8
      10       3       
    1    6        14
       4   17   13  
************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left_child;
    node* right_child;

    node(int d){
        this->data=d;
        this->left_child=NULL;
        this->right_child=NULL;
    }
};

node* Build_Tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node *n=new node(d);
    n->left_child=Build_Tree();
    n->right_child=Build_Tree();
    return n;
}

void print_pre(node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" ";
    print_pre(n->left_child);
    print_pre(n->right_child);
}

void print_in(node *root){
    if(root==NULL){
        return;
    }
    print_in(root->left_child);
    cout<<root->data<<" ";
    print_in(root->right_child);
}

void print_post(node *root){
    if(root==NULL){
        return;
    }
    print_post(root->left_child);
    print_post(root->right_child);
    cout<<root->data<<" ";
}

int main() {
    node* root=Build_Tree();
    print_pre(root);
    cout<<endl;
    print_in(root);
    cout<<endl;
    print_post(root);
    return 0;
}
