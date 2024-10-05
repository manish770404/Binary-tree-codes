#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data= val;
        left=NULL;
        right=NULL;
        
    }
};

int level(Node* r, int X)
{
    Node* node;
     if (r == NULL)
        return 0;
     queue<Node*> q;
  int currLevel = 1;
    q.push(r);
    while (q.empty() == false) {
        int size = q.size();
        while (size--) {
            node = q.front();
            if (node->data == X)
                return currLevel;
            q.pop();
           if (node->left != NULL)
                q.push(node->left);
           if (node->right != NULL)
                q.push(node->right);
        }
        currLevel++;
    }
    return 0;
}
 
bool isSibling(Node* r, Node* a,Node* b)
{
if (r== NULL)
{return false;
}
if(r->left == a && r->right == b)
{
return true;
}
if(r->left == b && r->right == a)
{
return true;
}
return (isSibling(r->left, a, b)|| isSibling(r->right, a, b));
}


bool iscousine(Node* r,Node* a,Node* b)
{
if ((level(r, a->data) == level(r, b->data)) && !(isSibling(r, a, b)))
{
return true;
}

return false;
}

int main()
{
    struct Node* r=new Node(15);

    r->left=new Node(5);
    r->right=new Node(20);
     r->left->left=new Node(10);
      r->left->right=new Node(19);
       r->right->left=new Node(21);
       r->right->right=new Node(18);
       
       Node* n1 = r->left->left;
       Node* n2 = r->right->right;
 
       if(iscousine( r,n1,n2))
       {
           cout<<"is cousine"<<endl;
       }
       else
       {
           cout<<"not cousine"<<endl;
       }

       return 0;
    
}

