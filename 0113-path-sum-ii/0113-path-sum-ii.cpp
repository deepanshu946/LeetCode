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
vector<vector<int>> ans;
    void solve(TreeNode* root , int target , int curr , vector<int> &temp){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(curr + root->val == target){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            return ;
        }
        temp.push_back(root->val);
        solve(root->left , target , curr + root->val , temp);
        solve(root->right , target , curr + root->val , temp);
        temp.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum, 0 , temp);
        return ans;
    }
};