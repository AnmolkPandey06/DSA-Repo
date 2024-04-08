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
    TreeNode * findMaxi(TreeNode * root,TreeNode *parent){
        bool flag=false;
        while(root->right!=NULL){
            flag=true;
            parent=root;
            root=root->right;
            
        }
        if(flag==true){
            parent->right=root->left;
        }
        else{
            parent->left=root->left;
        }
        return root;

    }
   

    TreeNode * deleter(TreeNode* root,int key) {
         
        // if(!root) return NULL;
        // int n=root->val;
        // if(val==n) return root;
        // if(val<n) return searchBST(root->left,val);
        // else return searchBST(root->right,val);
        if(!root) return root;
        if(root->val==key){
           //delete
           if(!root->right && !root->left){
               delete root;
               return NULL;
           }
           if(!root->right && root->left){
               TreeNode * temp=root->left;
               delete root;
               return temp;
           }

           if(root->right && !root->left){
               TreeNode * temp=root->right;
               delete root;
               return temp;
           }

           else{
               TreeNode * predmaxi=findMaxi(root->left,root);
               predmaxi->right=root->right;
               predmaxi->left=root->left;
               delete root;
               return predmaxi;
               


           }
           
        }
        if(root->val<key){
                root->right=deleter(root->right,key);
                return root;
        } 
        else{
            root->left=deleter(root->left,key);
            return root;
        }  
 
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //search the root
        // TreeNode *del=searchBST(root,key);
        return deleter(root,key);
        
    }
};