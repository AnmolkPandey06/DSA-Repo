/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // void findingthepath(TreeNode* root, TreeNode* p,vector<TreeNode *> &n1,int &flag){
    //     if(!root) return ;
    //     if(root==p) {
    //         flag=1;
    //         n1.push_back(root);
    //         return;
    //     }
    //     if(flag!=1){
    //         findingthepath(root->left,p,n1,flag);
    //     }
    //     if(flag!=1){
    //         findingthepath(root->right,p,n1,flag);
    //     }
    //     if(flag==1){
    //         n1.push_back(root);
    //     }
    // }
    
    // TreeNode * checktheLCA(vector<TreeNode *> n1,vector<TreeNode *> n2){
    //     reverse(n1.begin(),n1.end());
    //     reverse(n2.begin(),n2.end());
    //     int mini=min(n1.size(),n2.size());
    //     TreeNode * ans;
    //     for(int i=0;i<mini;i++){
    //         if(n1[i]==n2[i]){
    //             ans=n1[i];
    //         }
    //     }
    //     return ans;
    // }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //  vector <TreeNode *> n1;
        //  vector <TreeNode *> n2;
        //  int flag=0;
        //  findingthepath(root,p,n1,flag);
        //  flag=0;
        //  findingthepath(root,q,n2,flag);
        // TreeNode * ans= checktheLCA(n1,n2);
        // return ans;
        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode *left= lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL && right==NULL) return NULL;
        if(left && right==NULL) return left;
        if(left==NULL && right) return right;
        if(left && right) return root;

        return root;
    }
};
