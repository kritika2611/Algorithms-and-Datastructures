//INPUT: 8 5 15 4 7 13 3 5 6 11 14 9 12 -1

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

node* insert_(node* root, int d){
    if(root==NULL){
        node *n=new node(d);
        return n;
    }

    if(d<=root->data) root->left=insert_(root->left,d);
    else root->right=insert_(root->right,d);
    return root;
}

node* BST_Tree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node* root=NULL;
    while(d!=-1){
        root=insert_(root,d);
        cin>>d;
    }
    return root;    
}

void print_BFS(node* root){
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
            if(!q.empty()) q.push(NULL);
            continue;
        }

        cout<<f->data<<" ";
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}

int max_(node* root){
    //base case
    if(root->right==NULL) return root->data;

    //recursive case
    return max_(root->right);
}

node* delete_(node* root, int d){
    //base case
    if(root==NULL) return NULL;

    if(root->data==d){
        if(root->left==NULL && root->right==NULL) return NULL;  //leaf node
        if(root->left==NULL || root->right==NULL){            //1 child
            if(root->left!=NULL) return root->left;
            else if(root->right!=NULL) return root->right;
        }
        //both children
        int e=max_(root->left);
        root->data=e;
        root->left=delete_(root->left,e);
        return root;
    }

    //recursive case
    if(d<=root->data)
        root->left=delete_(root->left,d);
    else root->right=delete_(root->right,d);
    return root;
}

int main(){
    node* root=BST_Tree();
    print_BFS(root); cout<<endl;
    delete_(root,13);
    print_BFS(root); cout<<endl;
    delete_(root,15);
    print_BFS(root);
	return 0;
}