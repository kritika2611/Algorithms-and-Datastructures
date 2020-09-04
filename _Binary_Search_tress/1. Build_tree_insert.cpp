/****************************************************************************************************************************************************
Build a binary search tree by taking elements from the input. -1 represents the end of tree

Input: 5 8 3 4 2 9 7 1 6 5 -1

output:
inorder print-  1 2 3 4 5 5 6 7 8 9 
BFS-    5 
		3 8 
		2 4 7 9 
		1 5 6 
***************************************************************************************************************************************************/


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

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void bfs_print(node* root){
    if(root==NULL){
        return;
    }

    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }

        cout<<f->data<<" ";
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}
int main() {
    node* root=Build();
    //inorder print -- gives sorted output
    inorder(root);
    cout<<endl<<endl;
    //BFS
    bfs_print(root);
    return 0;
}
