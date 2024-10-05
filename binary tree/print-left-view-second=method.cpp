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

void printleftview(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    Node *p = NULL;
    while (!q.empty())
    {
        Node *c = q.front();
        q.pop();
        if (c != NULL)
        {
            if (c->left != NULL)
            {
                q.push(c->left);
            }
            if (c->right)
            {
                q.push(c->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        if (p == NULL)
        {
            cout << c->data << " ";
        }
        p = c;
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
    printleftview(root);
    return 0;
}