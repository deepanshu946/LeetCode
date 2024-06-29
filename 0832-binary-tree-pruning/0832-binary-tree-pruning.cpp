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
void solve(TreeNode*& root){
    if(root==NULL){
        return;
    }

    solve(root->left);
    solve(root->right);
    if(root->left==NULL &&root->right==NULL && root->val == 0){
        root=NULL;
        return;
    }
}

public:
    TreeNode* pruneTree(TreeNode* root) {
        solve(root);
        return root;
    }
};