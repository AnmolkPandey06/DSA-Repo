/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inordermaker(TreeNode* root,vector <TreeNode *> &inorder){
         if(root==NULL) return;
         inordermaker(root->left,inorder);
         inorder.push_back(root);
         inordermaker(root->right,inorder);
         return; 
    }
    
    TreeNode * treemaker(vector <TreeNode *> &inorder,int mini,int maxi){
        if(mini>maxi) return NULL;
        
        int mid=mini+(maxi-mini)/2;
        TreeNode * root=inorder[mid];
        root->left=treemaker(inorder,mini,mid-1);
        root->right=treemaker(inorder,mid+1,maxi);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
         vector <TreeNode *> inorder;
         if(!root) return NULL;
         //getting a inorder vector
         inordermaker(root,inorder);
         
         //TreeMaker function
         TreeNode * ans=treemaker(inorder,0,inorder.size()-1);
         return ans;
    }
};