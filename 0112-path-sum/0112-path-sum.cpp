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
bool solve(TreeNode* root , int target){
    if(root==NULL){
        return false;
    }
    if(target==root->val && root->left==NULL && root->right==NULL){
        return true;
    }

    bool left = solve(root->left,target-root->val);
    bool right = solve(root->right , target-root->val);
    return left||right;


}
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root , targetSum);
    }
};