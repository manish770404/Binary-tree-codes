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
int maxi(int x,int y)
{
    if (x > y)
    {
        return  x;
    }
    else
    {
        return  y;
    }
}

int maxsum(Node* r)
{
    if(r==NULL)
    {
        return 0;
    }
    int lsum=INT_MIN;
    int rsum=INT_MAX;

    lsum=maxsum(r->left);
    rsum=maxsum(r->right);

    int maxsum=r->data+maxi(lsum,rsum);

    return maxsum;
}
void preorder(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    else
        cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

int main()
{
    Node *r = new Node(5);
    r->left = new Node(2);
    r->right = new Node(-10);
    r->right->left = new Node(6);
    r->right->right = new Node(8);
    r->right->right->left = new Node(20);
    r->right->right->right = new Node(4);

     preorder(r);
     cout<<endl;
     cout<<maxsum(r);
     
    return 0;
}