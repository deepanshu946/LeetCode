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
void solve(TreeNode* root , int data , bool &ans){
    if(root==NULL){
        return;
    }
    solve(root->left,data,ans);
    solve(root->right , data , ans);
    if(root->val != data){
        ans = false;
    }

}
public:
    bool isUnivalTree(TreeNode* root) {
        int data = root->val;
        bool ans=1;
        solve(root,data,ans);
        return ans;
    }
};