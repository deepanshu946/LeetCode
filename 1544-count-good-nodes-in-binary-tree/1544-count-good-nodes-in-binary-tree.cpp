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
int solve(TreeNode* root , int value){
    if(root==NULL){
        return 0;
    }
    if(root->val >= value){
       return 1+ solve(root->left,root->val) + solve(root->right , root->val);
        
    }
    else{
        
        return solve(root->left,value)+solve(root->right , value);
    }

}
public:
    int goodNodes(TreeNode* root) {
        return  solve(root,INT_MIN);
    }
};