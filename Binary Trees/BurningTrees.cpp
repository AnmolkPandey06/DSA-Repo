//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    void CreateParentmap(Node *root,map<Node*,Node *> &parent){
        queue <Node*> q;
        parent[root]=NULL;
        q.push(root);
        while(!q.empty()){
           Node * temp=q.front();
           q.pop();
           if(temp->left){
               q.push(temp->left);
               parent[temp->left]=temp;
           }
           
           if(temp->right){
               q.push(temp->right);
               parent[temp->right]=temp;
           }
        }
        
    }
    
    Node * targetfinder(Node *root,int target,map <Node*,bool> &visited){
        if(!root) return NULL;
        if(root->data==target){
            visited[root]=false;
            return root;
        }
        
        visited[root]=false;
        Node *left=targetfinder(root->left,target,visited);
        Node *right=targetfinder(root->right,target,visited);
        
        if(!left && ! right) return NULL;
        if(!left &&  right)  return right;
        if(left &&  !right)  return left;
        return NULL;
    }
    
    
    int BurningTree(Node *root,map <Node*,bool> &visited,Node *targetNode, map <Node *,Node *> parent){
        int time=0;
        queue <Node *> q;
        q.push(targetNode);
        visited[targetNode]=true;
        
        while(!q.empty()){
           
            int size=q.size();
            
            bool flag=false;
            while(size--){
                 Node * temp=q.front();
                 q.pop();
                if(parent[temp]!=NULL){
                Node * par=parent[temp];
                if(!visited[par]){
                    flag=true;
                    q.push(par);
                    visited[par]=true;
                }
            }
            if(temp->left){
                Node * left=temp->left;
                if(!visited[left]){
                    flag=true;
                    q.push(left);
                    visited[left]=true;
                }
            }
            if(temp->right){
                Node * right=temp->right;
                if(!visited[right]){
                    flag=true;
                    q.push(right);
                    visited[right]=true;
                }
              }    
            }
            
            if(flag){
                time++;
            }
            // if(q.size()!=size){
            //     time++;
            //     size=q.size();
            // }
           
        }
        
        return time;
        
        

        
    }
    
    int minTime(Node* root, int target) 
    {
        //Creating Parent map
        map<Node*,Node *> parent;
        CreateParentmap(root,parent);
        
        //finding the target Node
        map <Node*,bool> visited;
        Node *targetNode=targetfinder(root,target,visited);
        
        
        //Now calculating time for burning
                
        int time=BurningTree(root,visited,targetNode,parent);
        return time;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends