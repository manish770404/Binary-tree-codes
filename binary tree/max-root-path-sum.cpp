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


int maxpathsum(Node *r, int s)
{
    if(r==NULL)
    {
        return s;
    }


    int rleft = maxpathsum(r->left, s + r->data);
    int rright = maxpathsum(r->right, s + r->data);
cout<<"\n"<<r->data<<" : "<<rleft<<":"<<rright;
    return maxi(rleft , rright);
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
     cout<<maxpathsum(r,0);

    return 0;
}