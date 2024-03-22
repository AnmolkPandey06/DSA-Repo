#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildNode(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    if (data == -1)
        return NULL;
    root = new node(data);

    cout << "Enter the value of left to node with  , to put null write -1. Node data=" << data << endl;
    root->left = buildNode(root->left);

    cout << "Enter the value of right , to put null write -1.Node data=" << data << endl;
    root->right = buildNode(root->right);

    return root;
}




void levelordertraversal(node *root)
{
    queue <node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            { // next line ke laga diya
                q.push(NULL);
            }
        }
        else
        {   
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        
    }
}



void recur_inorder(node * root){
    // base case if  
    if(root==NULL) return ;
    
    recur_inorder(root->left);
    cout<<root->data<<" ";
    recur_inorder(root->right);
    return;
}


void recur_preorder(node * root){
    // base case if  
    if(root==NULL) return ;
    
    
    cout<<root->data<<" ";
    recur_preorder(root->left);
    recur_preorder(root->right);
    return;
}


void recur_postorder(node * root){
    // base case if  
    if(root==NULL) return ;
    
    
    
    recur_postorder(root->left);
    recur_postorder(root->right);
    cout<<root->data<<" ";
    return;
}

node * builfromlevelorder(node * root){
    queue <node *> q;
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    if (data == -1) return NULL;
    
    root = new node(data);
    q.push(root);

    while(!q.empty()){
         node * temp=q.front();
         q.pop();
         
         cout<<"Enter value  of left node for:"<<temp->data<<endl;
         int leftdata=0;
         cin>>leftdata;

         if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
         }


         cout<<"Enter value  of right node for:"<<temp->data<<endl;
         int rightdata=0;
         cin>>rightdata;

         if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
         }
    }
    return root;

}




int main()
{
    cout << "Lets meake your tree" << endl;
    //node *root = buildNode(root);
    node *root=builfromlevelorder(root);
    levelordertraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"Inorder Recursive"<<endl;
    // recur_inorder(root);
    // cout<<endl<<"Preorder Recursive"<<endl;
    // recur_preorder(root);
    // cout<<endl<<"Inorder Recursive"<<endl;
    // recur_postorder(root);
    return 0;
}