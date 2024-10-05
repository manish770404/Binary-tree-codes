#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data =val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct Node* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return ;
    }
     inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(struct Node* root)
{
    if(root==NULL)
    {
        return ;
    }
     postorder(root->left);
    postorder(root->right);
      cout<<root->data<<" ";

}
int main()
{
    struct Node* root=new Node(15);

    root->left=new Node(5);
    root->right=new Node(20);
     root->left->left=new Node(10);
      root->left->right=new Node(19);
       root->right->left=new Node(21);
       root->right->right=new Node(18);
       cout<<"preorder traversal is:"<<endl;

       preorder(root);
       cout<<"postorder traversal is:"<<endl;
        postorder(root);
         cout<<"inorder traversal is:"<<endl;
            inorder(root);


       return 0;
       
       }