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

node* Tree_(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* n=new node(d);
    n->left=Tree_();
    n->right=Tree_();
    return n;
}

void display(queue <node*> q){
    if(q.empty()){
        return;
    }

    while(!q.empty()){
        node *f=q.front();
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

node* tree_from_arr(int *arr,int s,int e){
    //base case
    if(s>e){
        return NULL;
    }

    //recursive case
    int mid=(s+e)/2;
    node *n=new node(arr[mid]);
    n->left=tree_from_arr(arr,s,mid-1);
    n->right=tree_from_arr(arr,mid+1,e);
    return n;
}

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node *root=tree_from_arr(arr,0,n-1);
    queue <node*> q;
    if(root!=NULL){
        q.push(root);
        q.push(NULL);
    }
    display(q);
    return 0;
}