#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* TREE(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node *n=new node(d);
    n->left=TREE();
    n->right=TREE();
    return n;
}

int total_nodes(node *root){
    //base recursive case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int l=total_nodes(root->left);
    int r=total_nodes(root->right);
    return l+r+1;
}

int nodes_sum(node* root){
    //base case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int l=nodes_sum(root->left);
    int r=nodes_sum(root->right);
    return l+r+root->data;
}

int main(){
    node *root=TREE();
    cout<<total_nodes(root)<<endl;
    cout<<nodes_sum(root);

    return 0;
}