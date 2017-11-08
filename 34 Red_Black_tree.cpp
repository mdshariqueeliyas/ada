#include<iostream>
using namespace std;
class node
{
public:
node *left;
node *right;
node *p;
int info;
char color;
node()
{
left=0;
right=0;
p=0;
info=0;
color='b';
}
node (int x)
{
info=x;
p=new node();
}
};
class rb_tree
{
public:
node *root;
node *nil;
rb_tree()
{
nil=new node();
root=nil;
}
int isempty()
{
if (root==nil)
return 1;
else
return 0;
}
void insert(int);
void insert_fixup(node *z);
void left_rotate(node *x);
void right_rotate(node *x);
void inorder();
void inorder(node *);
node *search(node *,int);
node *deletion(node *);
void rb_delete_fixup(node *x);
void rb_transplant(node *u,node *v);
node *tree_minimum(node *);
};
void rb_tree::inorder()
{
inorder(root);
}
void rb_tree::inorder(node *x)
{
if(x!=nil)
{
inorder(x->left);
if(x->color=='b')
cout<<x->info<<"->B \t";
else
cout<<x->info<<"->R \t";
inorder(x->right);
}
}
void rb_tree::insert(int n)
{
node *z=new node(n);
node *y=nil;
node *x=root;
while(x!=nil)
{
y=x;
if(z->info<x->info)
x=x->left;
else
x=x->right;
}
z->p=y;
if(y==nil)
root=z;
else if (z->info<y->info)
y->left=z;
else
y->right=z;
z->left=nil;
z->right=nil;
z->color='r';
insert_fixup(z);
}
void rb_tree::insert_fixup(node *z)
{
node *y;
while(z->p->color=='r')
{
if(z->p==z->p->p->left)
{
y=z->p->p->right;
if(y->color=='r')
{
z->p->color='b';
y->color='b';
z->p->p->color='r';
z=z->p->p;
}
else
{
if (z==z->p->right)
{
z=z->p;
left_rotate(z);
}
z->p->color='b';
z->p->p->color='r';
right_rotate(z->p->p);
}
}
else
{
y=z->p->p->left;
if(y->color=='r')
{
z->p->color='b';
y->color='b';
z->p->p->color='r';
z=z->p->p;
}
else
{
if (z==z->p->left)
{
z=z->p;
right_rotate(z);
}
z->p->color='b';
z->p->p->color='r';
left_rotate(z->p->p);
}
}
}
root->color='b';
}
void rb_tree::left_rotate(node *x)
{
node *y=x->right;
x->right=y->left;
if (y->left!=nil)
y->left->p=x;
y->p=x->p;
if(x->p==nil)
root=y;
else if(x==x->p->left)
x->p->left=y;
else
x->p->right=y;
y->left=x;
x->p=y;
}
void rb_tree::right_rotate(node *x)
{
node *y=x->left;
x->left=y->right;
if (y->right!=nil)
y->right->p=x;
y->p=x->p;
if(x->p==nil)
root=y;
else if(x==x->p->right)
x->p->right=y;
else
x->p->left=y;
y->right=x;
x->p=y;
}
node *rb_tree :: search(node *x,int k)
{
if(x==nil)
return x;
else if(k==x->info)
return x;
else if(k<x->info)
return search(x->left,k);
else
return search(x->right,k);
}
node *rb_tree :: deletion(node *z)
{
node *y,*x;
y=z;
char y_original_color=y->color;
if(z->left==nil)
{
x=z->right;
rb_transplant(z,z->right);
}
else if(z->right==nil)
{
x=z->left;
rb_transplant(z,z->left);
}
else
{
y=tree_minimum(z->right);
y_original_color=y->color;
x=y->right;
if(y->p==z)
x->p=y;
else
{
rb_transplant(y,y->right);
y->right=z->right;
y->right->p=y;
}
rb_transplant(z,y);
y->left=z->left;
y->left->p=y;
y->color=z->color;
}
if(y_original_color=='b')
rb_delete_fixup(x);
}
void rb_tree :: rb_delete_fixup(node *x)
{
node *w;
while((x!=root)&&(x->color=='b'))
if(x==x->p->left)
{
w=x->p->right;
if(w->color=='r')
{
w->color='b';
x->p->color='r';
left_rotate(x->p);
w=x->p->right;
}
if((w->left->color=='b')&&(w->right->color=='b'))
{
w->color='r';
x=x->p;
}
else if(w->right->color=='b')
{
w->left->color='b';
w->color='r';
right_rotate(w);
w==x->p->right;
}
w->color=x->p->color;
x->p->color='b';
w->right->color='b';
left_rotate(x->p);
x=root;
}
else
{
if(x==x->p->right)
{
w=x->p->left;
if(w->color=='r')
{
w->color='b';
x->p->color='r';
right_rotate(x->p);
w=x->p->left;
}
if((w->right->color=='b')&&(w->left->color=='b'))
{
w->color='r';
x=x->p;
}
else if(w->left->color=='b')
{
w->right->color='b';
w->color='r';
left_rotate(w);
w==x->p->left;
}
w->color=x->p->color;
x->p->color='b';
w->left->color='b';
right_rotate(x->p);
x=root;
}
}
x->color='b';
}
void rb_tree :: rb_transplant(node *u,node*v)
{
if(u->p==nil)
root=v;
else if(u==u->p->left)
u->p->left=v;
else
u->p->right=v;
v->p=u->p;
}
node *rb_tree :: tree_minimum(node *a)
{
while(a->left!=nil)
a=a->left;
return a;
}
int main()
{
int x,choice;
rb_tree r1;
char ch;
cout<<"*******MENU DRIVEN PROGRAM*******"<<endl;
cout<<"1. Insertion"<<endl;
cout<<"2. Deletion"<<endl;
cout<<"3. Inorder Traversal"<<endl;
cout<<"4. Search"<<endl;
do
{
cout<<"enter your choice"<<endl;
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"Enter the element which you want to insert:"<<endl;
cin>>x;
r1.insert(x);
r1.inorder();
break;
}
case 2:
{
cout<<"enter the element u want to delete"<<endl;
cin>>x;
node *s=r1.search(r1.root,x);
if(s!=r1.nil)
{
r1.deletion(s);
r1.inorder();
cout<<endl;
}
else
cout<<"Node is not present in the tree"<<endl;
break;
}
case 3:
{
cout<<"The inorder traversal of the tree is"<<endl;
r1.inorder();
cout<<endl;
break;
}
case 4:
{
cout<<"enter the element u want to search"<<endl;
cin>>x;
node *s=r1.search(r1.root,x);
if(s!=r1.nil)
{
cout<<"Node is present in the tree"<<endl;
cout<<"The color of the searched node "<<s->info<<" is "<<s->color<<endl;
}
else
cout<<"node is not present in the tree"<<endl;
break;
}
}
cout<<"do you want to continue?"<<endl;
cin>>ch;
}
while(ch=='y');
return 0;
}
