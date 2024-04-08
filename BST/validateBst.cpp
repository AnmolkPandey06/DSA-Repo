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
    bool checkBST(TreeNode* root, long long int mini,long long int  maxi){
        if(!root) return true;
        bool right=checkBST(root->right,root->val,maxi);
        bool left=checkBST(root->left,mini,root->val);
        bool check=false;
        // if( !minlock){
        //    if(root->val>=mini && root->val<maxi) check=true;
        //    minlock=true;
        // }
        // else if(mini!=INT_MIN && maxi==INT_MAX && !maxlock){
        //     if(root->val>mini && root->val<=maxi) check=true;
        //     maxlock=true;
        // }
        // else if(mini==INT_MIN && maxi==INT_MAX && !maxlock && !minlock){
        //     if(root->val>=mini && root->val<=maxi) check=true;
        //     minlock=true;
        //     maxlock=true;
        // }
        // else{
            
        // }
        if(root->val>mini && root->val<maxi) check=true;
        return (right & left) & check;
        
        }
    bool isValidBST(TreeNode* root) {
      long long mini=-1000000000000;
      long long maxi=+1000000000000;
      return checkBST(root,mini,maxi);
      

    }
};