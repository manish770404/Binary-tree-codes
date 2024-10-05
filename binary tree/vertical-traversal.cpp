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