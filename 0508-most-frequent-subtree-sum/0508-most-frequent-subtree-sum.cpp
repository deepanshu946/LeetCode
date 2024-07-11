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
int solve(TreeNode* root , unordered_map<int,int> &m){
    if(root==NULL){
        return 0;
    }
    int left = solve(root->left,m);
    int right = solve(root->right,m);
    int sum = left+right+root->val;
    m[sum]++;
    return sum;

}
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        solve(root,m);
        vector<int> ans;
        int maxi=INT_MIN;
        for(auto i:m){  
            maxi = max(maxi,i.second);
        }
        for(auto i:m){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};