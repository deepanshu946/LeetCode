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
private:
int finalans = INT_MIN;
int solve(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left = solve(root->left);
    int right = solve(root->right);
    int ans = 1;
    if(root->left != NULL && root->val==root->left->val){
        ans = ans + left;
    }
    else{
        left=0;
    }
    if(root->right != NULL && root->val==root->right->val){
        ans = ans + right;
    }
    else{
        right=0;
    }
    finalans = max(ans, finalans);
    return max(left+1 , right+1);

}
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        solve(root);
        return finalans-1;
    }
};