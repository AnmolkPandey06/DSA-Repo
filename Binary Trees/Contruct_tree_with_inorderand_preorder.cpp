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
    void createIndex(vector<int> &inorder,map <int,int> &mp,int n){
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return;
    }
    TreeNode * solve(map <int,int> &mp,vector<int> &preorder, vector<int> &inorder,int &preindex,int in_start,int in_end,int n){
        if(preindex>=n || in_start>in_end){
            return NULL;
        }
        int element=preorder[preindex++];
        TreeNode * root=new TreeNode(element);
        int position=mp[element];
        root->left=solve(mp,preorder,inorder,preindex,in_start,position-1,n);
        root->right=solve(mp,preorder,inorder,preindex,position+1,in_end,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int preIndex=0;
       int n=preorder.size();
        map <int,int> mp;
       createIndex(inorder,mp,n);
       TreeNode * root=solve(mp,preorder,inorder,preIndex,0,n-1,n);
       return root;
    }
};