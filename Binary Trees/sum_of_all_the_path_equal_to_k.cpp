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
    void solve(TreeNode* root,vector<int> ans,int &count,int k){
        if(!root) return;
        ans.push_back(root->val);
        solve(root->left,ans,count,k);
        solve(root->right,ans,count,k);

        long long int sum=0;
        for(int i=ans.size()-1;i>=0;i--){
            sum=sum+ans[i];
            if(sum==k){
                count++;
            }
        }
        ans.pop_back();


    }
    int pathSum(TreeNode* root, int targetSum) {
        vector <int> ans;
        int count=0;
        solve(root,ans,count,targetSum);
        return count;
    }
};