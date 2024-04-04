/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) {
    queue <TreeNode *> q;
    vector <int> ans;
    if(!root) return ans;
    
    q.push(root);
    while(!q.empty()){
        TreeNode * temp=q.front();
        q.pop();
        while(temp!=NULL){
            ans.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            temp=temp->right;
        }
    }
    return ans;
    
    
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root) {
    queue <TreeNode *> q;
    vector <int> ans;
    if(!root) return ans;
    
    q.push(root);
    while(!q.empty()){
        TreeNode * temp=q.front();
        q.pop();
        while(temp!=NULL){
            ans.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            temp=temp->right;
        }
    }
    return ans;
    
    
}
