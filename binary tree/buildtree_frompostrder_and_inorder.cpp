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
int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
        return i;
        }
    }
    return -1;
}

Node *buildtree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
if(start>end)
{
    return NULL;
}
    int val = postorder[idx];
    idx--;
    Node* node = new Node(val);
    if(start==end)
    {
        return node;
    }

    int pos = search( inorder, start, end,val);

    node->right = buildtree(postorder, inorder, pos + 1, end);
    node->left = buildtree(postorder, inorder, start, pos - 1);

    return node;
}
void printinorder(struct Node* root)
{
    if(root==NULL)
    {
        return ;
    }
     printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);

}
int main()
{
    int postorder[]={ 4,2,5,3,1};
    int inorder []={4,2,1,5,3};

    Node* root=buildtree(postorder,inorder,0,4);

    cout<<"tree builded:";

    printinorder(root);

    return 0;
}