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
void levelordertraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
          q.pop();
        if (node != NULL)
        {
            cout << node->data<<" ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }

            if (node->right != NULL) 
            {
                q.push(node->right);
            }
         
        }
        else if (!q.empty())
        {
            cout<<endl;
            q.push(NULL);
        }
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

    levelordertraversal(root);


    return 0;
}