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
void solve(int &ans , TreeNode* root , int val , int val2){
    if(root==NULL){
        return ;
    }
    ans = max(ans,max(abs(root->val-val),abs(root->val-val2)));
    solve(ans,root->left,max(val,root->val) , min(val2,root->val));
    solve(ans,root->right,max(val,root->val),min(val2,root->val));
}
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        solve(ans,root,root->val,root->val);
        return ans;
    }
};