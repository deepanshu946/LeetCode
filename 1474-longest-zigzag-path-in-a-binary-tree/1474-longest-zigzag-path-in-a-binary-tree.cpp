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
int ans = INT_MIN;
int solve(TreeNode* root , bool left ){
    if(root==NULL){
        return 0;
    }
    int leftans = solve(root->left,1);
    int rightans = solve(root->right,0);
    ans = max(ans,max(leftans,rightans));

    if(left==0){
        return 1+leftans;
    }
    else{
        return 1+rightans;
    }

    


}
public:

    int longestZigZag(TreeNode* root) {
        solve(root,0);
        return ans;
        
    }
};