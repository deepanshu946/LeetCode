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
void solve(TreeNode* &root , unordered_set<int> s , vector<TreeNode*> &ans){
    if(root==NULL){
        return ;
    }
    solve(root->left,s,ans);
    solve(root->right,s, ans);
    if(s.find(root->val) != s.end()){
        if(root->left != NULL){
            ans.push_back(root->left);
        }
        if(root->right != NULL){
            ans.push_back(root->right);
        }
        root=NULL;
    }
}
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s;
        s.insert(to_delete.begin() , to_delete.end());
        solve(root,s,ans);
        if(root != NULL){
            ans.push_back(root);
        }
        return ans;
    }
};