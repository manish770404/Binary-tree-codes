#include<iostream>
using namespace std;

class node
{
    public:

    int val;
    node* left;
    node* right;


    node(int data)
    {
        val=data;
        left=NULL;
        right =NULL;
    }
   

};
 node* buildtree( node* root)
 {
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter the data for inserting into left"<<data<<endl;

    root->left=buildtree(root->left);
    cout<<"enter th data for inserting into right "<<data<<endl;
     root->right=buildtree(root->left);

     return root;
 }

int main()
{
    node* root= NULL;
     root =buildtree(root);

}