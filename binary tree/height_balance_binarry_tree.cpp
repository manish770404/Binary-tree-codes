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
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;
}
bool isbalanced(Node* root)
{
        if(root==NULL)
        {
            return true;
        }
       if(isbalanced(root->left)==false)
       {
        return false;
       }
       
       if(isbalanced(root->right)==false)
       {
        return false;
       }

       int lh=height(root->left);
       int rh=height(root->right);
       if(abs(lh-rh)<=1)
       {
        return true;
       }
       else{
        return false;
       }

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

    bool res=isbalanced(root);
    cout<<res;



    return 0;
}
