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
int solve(TreeNode* root ){
     if(root==NULL){
            return 1e9;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }

        int left = solve(root->left);
        int right = solve(root->right);
        return min(left,right)+1;
         
}
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
       
       return solve(root);

    }
};