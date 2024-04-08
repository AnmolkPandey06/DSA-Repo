//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    // void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    // {
    //     //find key
        
    //     pre=NULL;
    //     suc=NULL;
    //     if (!root) return;
    //     while( root!=NULL  && root->key!=key){
    //         if(root->key<key){
    //             pre=root;
    //             root=root->right;
    //         }
    //         if(root->key>key){
    //             suc=root;
    //             root=root->left;
    //         }
    //     }
        
        
    //     //now got root of key
    //     if(root){
    //     Node * left=root->left;
    //     while(left!=NULL){
    //         pre=left;
    //         left=left->right;
    //     }
        
        
    //     Node * right=root->right;
    //     while(right!=NULL){
    //         suc=right;
    //         right=right->left;
    //     }
    //     }
        
    // }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;

    while (root != NULL) {
        // If key is found
        if (root->key == key) {
            // Predecessor is the maximum value in the left subtree
            if (root->left) {
                Node* temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }

            // Successor is the minimum value in the right subtree
            if (root->right) {
                Node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
            return;
        }

        // If key is greater than the current node, update pre and move right
        if (root->key < key) {
            pre = root;
            root = root->right;
        }
        // If key is smaller than the current node, update suc and move left
        else {
            suc = root;
            root = root->left;
        }
    }
}

};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}
// } Driver Code Ends