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
void solve(TreeNode* root , int &ans , int temp){
    if(root->left==NULL && root->right==NULL){
        ans = ans + temp;
        return;
    }
    if(root->left)
        solve(root->left , ans , temp*10 + root->left->val);
    if(root->right)
        solve(root->right , ans , temp*10 + root->right->val);

}
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root,ans,root->val);
        return ans;
    }
};