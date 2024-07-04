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
int solve(TreeNode* root ,unordered_map<TreeNode*,int> &dp){
    if(root==NULL){
        return 0;
    }
    if(dp.count(root)){
        return dp[root];
    }
    int ans = 0;
    int include =0;
    int exclude=0;

        include = root->val;
        if(root->left){
           include+= solve(root->left->left,dp) + solve(root->left->right , dp);
        }
        if(root->right){
            include += solve(root->right->right,dp) + solve(root->right->left,dp);
        }
    exclude = solve(root->left,dp) + solve(root->right,dp);
    return dp[root]= max(include,exclude);
}
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root,dp);
    }
};