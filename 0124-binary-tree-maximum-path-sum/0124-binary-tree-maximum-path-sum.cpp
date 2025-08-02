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
int solve(TreeNode* root , int &ans){
    if(root==NULL){
        return 0;
    }
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    cout<<l<<" "<<r<<root->val<<endl;
    int temp = max(l+r+root->val,max(root->val,max(r+root->val,l+root->val))) ;
    ans = max(ans , temp);
    return max(l+root->val,max(root->val,r+root->val));

}
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int t = solve(root,ans);
        return ans;
    }
};