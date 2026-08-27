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
    unordered_map<long long , int> m;
    void solve(TreeNode* root , int target  , long long curr ){
        if(root==NULL){
            return;
        }
        // temp.push_back(root->val);
        curr += root->val;
        if(m.find(curr - target) != m.end()){
            ans += m[curr-target];
        }
        m[curr]++;

        solve(root->left , target ,curr);
        solve(root->right , target ,curr);
        
        m[curr]--;
        if(m[curr]==0){
            m.erase(curr);
        }


    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> temp ;
        m[0] = 1;
        solve(root , targetSum ,0);
        return ans;
    }
};