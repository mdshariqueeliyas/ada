#include<bits/stdc++.h>
using namespace std;

struct node{
	int key;
	node* left;
	node* right;
};

node * minnode(node* node)
{
    struct node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

node* insert(int val, node *root){	
	if (root == NULL){
		node *tmp= new node;
		tmp->key=val;
		tmp->left=tmp->right=NULL;
		return tmp;
	}
    if (val < root->key)
        root->left  = insert(val, root->left);
    else if (val > root->key)
        root->right = insert(val, root->right);   
    return root;
}

node* search(int val, node *root){
	if(root==NULL||val==root->key)
		return root;
	if(root->key>val)
		return search(val,root->left);
	return search(val,root->right); 
}

node* deleteNode(int val, node *root){
	if (root == NULL) return root;
    if (val < root->key)
        root->left = deleteNode(val, root->left);
    else if (val > root->key)
        root->right = deleteNode(val, root->right);
    else{    
        if (root->left == NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }      
        node* temp = minnode(root->right);
        root->key = temp->key;
        root->right = deleteNode(temp->key, root->right);
    }
    return root;
	
}

void print(node *root){
	if(root!=NULL){
		print(root->left);
		cout<<'\t'<<root->key;
		print(root->right);
	}
}

int main(){
	int opt,d;
	char ch='y';
	node *root=NULL;
	cout<<"..........Binary Search Tree Program..........\n";
	do{
		cout<<"\n\n1.Insertion\n2.Deletion\n3.Print\n4.Search\n\nSelect any operation:";
		cin>>opt;
		switch(opt){
			case 1: cout<<"\nEnter node: ";
					cin>>d;
					root=insert(d,root);
					break;
			case 2: cout<<"\nEnter node: ";
					cin>>d;
					root=deleteNode(d,root);
					break;
			case 3: cout<<'\n';
					print(root);
					break;
			case 4: cout<<"\nEnter node: ";
					cin>>d;
					if(search(d,root))
						cout<<"\nNode found.";
					else 
						cout<<"\nNode not found.";
					break;
			default: cout<<"\nWrong choice\n";
		}
		cout<<"\n\nDo you want to continue?(y/n)\n";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
}
