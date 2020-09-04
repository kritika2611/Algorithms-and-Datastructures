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

node* built_tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* n=new node(d);
    n->left=built_tree();
    n->right=built_tree();

    return n;
}

int find_height(node *root){
    //base case
    if(root==NULL){
        return 0;
    }
    //recursive case
    int lh=find_height(root->left);
    int rh=find_height(root->right);
    return max(lh,rh)+1;
}

void print_level(node *root,int l){
    //base case
    if(root==NULL){
        return;
    }
    if(l==1){
        cout<<root->data<<" ";
        return;
    }
    
    //recursive call
    print_level(root->left,l-1);
    print_level(root->right,l-1);
}

void level_print(node* root){
    int h=find_height(root);
    for(int i=1;i<=h;i++){
        print_level(root,i);
        cout<<endl;
    }
}

int main(){
    node* root=built_tree();
    level_print(root);

    return 0;
}