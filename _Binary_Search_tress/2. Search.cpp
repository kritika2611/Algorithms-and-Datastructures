/**********************************************************************************************************************************************************
make a function that returns the address of the key in the tree. If key is not present return NULL.

INPUT:
5 8 3 4 2 9 7 1 6 5 -1
7

OUTPUT: The key is present at index x056785142678
***********************************************************************************************************************************************************/

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

node* Search(node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }

    //recursive case
    if(key<=root->data){
        return Search(root->left,key);
    }
    return Search(root->right,key);
}


int main() {
    node* root=Build();
    int key;
    cin>>key;
    node* ans=Search(root,key);
    if(ans==NULL)
        cout<<key<<" is not present"<<endl;
    else
        cout<<key<<" is present at address "<<ans<<endl;
    
    return 0;
}
