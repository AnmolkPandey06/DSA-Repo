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
    int  Findk(TreeNode *root,int k,int & i){
        if(!root) return -1;
        int left=Findk(root->left,k,i);
        if(left!=-1){
            return left;
        }
        
        i++;

        if(k==i){
            return root->val; 
        }
        return Findk(root->right,k,i);
    }


    int kthSmallest(TreeNode* root, int k) {
        
        int i=0;
        int ans= Findk(root,k,i);
        return ans;
    }
};