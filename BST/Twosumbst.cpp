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
    bool searchBST( TreeNode * root  ,int value){
        while(root!=NULL){
            if(root->val==value) return true;
            if(root->val<value) root=root->right;
            else root=root->left;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        TreeNode * org=root;
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            int value=k-(temp->val);
            if(value!=temp->val){
                 if(searchBST(org,value)){
                 return true;
            }
            }
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false; 
    }
};