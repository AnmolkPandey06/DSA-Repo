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
    
    int check(TreeNode* root, bool &flag){
        if(root==NULL) return 0;
        int rh=check(root->right,flag);
        int lh=check(root->left,flag);
        if(abs(rh-lh)>1) flag=false;
        return 1+max(rh,lh);
    } 
    
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        int s=check(root,flag);
        return flag;
    }
};