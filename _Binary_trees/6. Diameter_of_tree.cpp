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

int height(node *root){
    //base case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int l_h=height(root->left);
    int r_h=height(root->right);
    return max(l_h,r_h)+1;
}

int diameter(node *root){
    //base case
    if(root==NULL){
        return 0;
    }

    //recursive case
    int hl=height(root->left);
    int hr=height(root->right);
    int ans_root=hl+hr;
    int ans_left=diameter(root->left);
    int ans_right=diameter(root->right);
    return max(max(ans_root,ans_left),ans_right);
}

int main(){
    node *root=TREE();
    cout<<diameter(root)<<endl;
    return 0;
}