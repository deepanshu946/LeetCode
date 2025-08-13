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
private:
int solve(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode* &ans){
    if(root==NULL){
        return 0;
    }
    
    int left = solve(root->left, p,q,ans);
    int right = solve(root->right, p,q,ans);
    
    if(left==1 && right==1){
        ans = root;
        // return 1;
    }
    else if(left==1 || right==1){
        if(root==p || root==q){
            ans=root;
        }
        return 1;
    }
    else if(root==p || root==q){
        cout<<root->val<<endl;
        return 1;
    }
    return 0;
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        solve(root,p,q,ans);
        return ans;

    }
};