int solve(Node *root,int k,int node,int &count,int &ans){
    if(!root) return -1;
    if(root->data==node){
      return node;  
    } 
    int left=solve(root->left,k,node,count,ans);
    int right=solve(root->right,k,node,count,ans);
    if(right==-1 && left==-1) return -1;
    if(right==-1 && left) {
        count++;
        if(count==k) ans=root->data;
        return left;
    }
    if(left==-1 && right) {
        count++;
        if(count==k) ans=root->data;
        return right;
    }
    return 0;
}


int kthAncestor(Node *root, int k, int node)
{   
    int ans=0;
    int count=0;
    int s=solve(root,k,node,count,ans);
    if(count<k) return -1;
    return ans;
}