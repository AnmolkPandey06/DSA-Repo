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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        q.push(root);
        vector <vector<int>> ans;
        if(!root) return ans;
        bool flag=true;
        while(!q.empty()){
            int size=q.size();
            vector <int> arr(size);
            for(int i=0; i<size;i++){
               TreeNode *temp=q.front();
               
               q.pop();
               int index=flag?(i):(size-1-i);
               arr[index]=temp->val;

               if(temp->left!=NULL) q.push(temp->left);
               if(temp->right!=NULL) q.push(temp->right); 

            }
           
            ans.push_back(arr);
            flag=!flag;


        }
        return ans;
    
    }
};