#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        left=NULL;
        right=NULL;
    }
};

node* Tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *n=new node(d);
    n->left=Tree();
    n->right=Tree();
    return n;
}

node* LCA(node *root, int a,int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a || root->data==b){
        return root;
    }

    node* l=LCA(root->left,a,b);
    node* r=LCA(root->right,a,b);

    if(l!=NULL && r!=NULL){
        return root;
    }
    if(l!=NULL && r==NULL){
        return l;
    }
    if(l==NULL && r!=NULL){
        return r;
    }
    return NULL;
}

//assumption that a and b are present and every data is unique
int main() {
    node* root=Tree();
    node* ans=LCA(root,9,10);
    cout<<ans->data;
    return 0;
}
