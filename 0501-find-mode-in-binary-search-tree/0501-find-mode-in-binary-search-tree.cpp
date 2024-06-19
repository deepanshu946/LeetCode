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
void solve(TreeNode* root , unordered_map<int,int> &m , int &max){
    if(root==NULL){
        return;
    }
    solve(root->left,m,max);
    m[root->val]++;
    if(m[root->val]>max){
        max = m[root->val];
    }
    solve(root->right,m,max);
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        int max = INT_MIN;

        solve(root,m,max);
        vector<int> ans;

        for(auto i:m){
            if(i.second==max){
                ans.push_back(i.first);
            }
        }
        return ans;

    }
};