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
int sumofsubtree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left = sumofsubtree(root->left);
    int right = sumofsubtree(root->right);
    return left + right + root->val;
}
int countsubtreenodes(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left = countsubtreenodes(root->left);
    int right = countsubtreenodes(root->right);
    return left + right + 1;
}
void solve(TreeNode* root , int &ans){
    if(root==NULL){
        return ;
    }
    int val = sumofsubtree(root)/countsubtreenodes(root);
    if(val == root->val){
        ans++;
    }
    solve(root->left , ans);
    solve(root->right , ans);
    return;
}
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};