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

void BFS_print(queue <node*> &q){
	node* n=q.front();
	if(q.empty()){
		return;
	}
	if(n==NULL){
		q.pop();
		BFS_print(q);
		return;
	}
	q.push(n->left);
	q.push(n->right);
	cout<<n->data<<" ";
	q.pop();
	BFS_print(q);
}


int main(){
	node* root=built_tree();
	queue <node*> q;
	q.push(root);
	BFS_print(q);

	return 0;
}