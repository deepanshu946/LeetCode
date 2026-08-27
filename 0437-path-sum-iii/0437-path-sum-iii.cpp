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
    int ans = 0;
    void solve(TreeNode* root , int target , vector<int> temp){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        solve(root->left , target , temp);
        solve(root->right , target , temp);
        long long curr = 0;
        for(int i=temp.size()-1 ; i>=0 ; i--){
            curr = curr + temp[i];
            if(curr == target){
                ans++;
            }
        }
        temp.pop_back();


    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp ;
        solve(root , targetSum , temp);
        return ans;
    }
};