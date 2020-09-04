/**************************************************************************************************************************************

INPUT:  8 5 4 3 5 7 6 15 13 11 14 -1

OUTPUT: 8 
        5 15 
        4 7 13 
        3 5 6 11 14 
**************************************************************************************************************************************/

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


int i=0;
node* to_BST(int min_,int max_,vector<int> pre){
    //base case
    if(i>=pre.size()) return NULL;

    if(pre[i]<min_ || pre[i]>max_)
        return NULL;

    //recursive case
    node* root=new node(pre[i]);
    i=i+1;
    root->left=to_BST(min_,root->data,pre);
    root->right=to_BST(root->data,max_,pre);
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

int main(){
    vector <int> pre;
    pre.reserve(100);
    
    int d;
    cin>>d;
    while(d!=-1){
        pre.push_back(d);
        cin>>d;
    }

    node* root=to_BST(INT_MIN,INT_MAX,pre);
    print_BFS(root);
    return 0;
}



