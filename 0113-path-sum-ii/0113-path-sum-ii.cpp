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
void solve(TreeNode* root , int sum , vector<vector<int>> &ans , vector<int> temp){
    if(root==NULL){
        return;
    }
    // if(root->left==NULL && root->right ==NULL && sum != 0){
    //     return;
    // }
    temp.push_back(root->val);
    solve(root->left,sum-root->val , ans, temp);
    solve(root->right,sum-root->val , ans, temp);
    if(root->left==NULL && root->right==NULL && sum==root->val){
        ans.push_back(temp);
    }
    temp.pop_back();
    
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,targetSum , ans , temp);
        return ans;
    }
};