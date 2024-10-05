#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}

int sumnodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return sumnodes(root->left)+sumnodes(root->right)+root->data;
}

int calcheight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);

    return max(lheight,rheight)+1;
}
int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int res=count(root);
    cout<<res;
    cout<<endl;  
    cout<<"sum of nodes are:";
    cout<<sumnodes(root)<<endl;
cout<<"height of the tree:";
cout<<calcheight( root);
    return 0;
}