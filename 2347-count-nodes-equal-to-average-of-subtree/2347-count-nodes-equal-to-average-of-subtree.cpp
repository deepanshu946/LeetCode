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
pair<int,int> sumofsubtree(TreeNode* root){
    if(root==NULL){
        return {0,0};
    }
    pair<int,int> left = sumofsubtree(root->left);
    pair<int,int> right = sumofsubtree(root->right);
    int sum = left.first+right.first+ root->val;
    int nodes = left.second+right.second+1;
    pair<int,int> p = make_pair(sum,nodes);
    return p;
}
// int countsubtreenodes(TreeNode* root){
//     if(root==NULL){
//         return 0;
//     }
//     int left = countsubtreenodes(root->left);
//     int right = countsubtreenodes(root->right);
//     return left + right + 1;
// }
void solve(TreeNode* root , int &ans){
    if(root==NULL){
        return ;
    }
    pair<int,int> p = sumofsubtree(root);
    int val = p.first/p.second;
    if(val == root->val){
        ans++;
    }
    solve(root->left , ans);
    solve(root->right , ans);
    return;
}
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};