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
    
    
    int diameterfind(TreeNode* root,int &dia){
        if(root==NULL) return 0;
        int lh=diameterfind(root->left,dia);
        int rh=diameterfind(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        diameterfind(root,diameter);  
        return diameter;
    }
};