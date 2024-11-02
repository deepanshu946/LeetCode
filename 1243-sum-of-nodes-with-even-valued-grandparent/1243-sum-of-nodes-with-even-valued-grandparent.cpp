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
void getparent(TreeNode* root ,unordered_map<TreeNode*,TreeNode*>&parent ){
    if(root==NULL){
        return;
    }
    if(root->left != NULL){
        parent[root->left]=root;
    }
    if(root->right != NULL){
        parent[root->right]=root;
    }
    getparent(root->left,parent);
    getparent(root->right,parent);
}
void solve(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &parent , int &ans){
    if(root==NULL){
        return;
    }
    if(parent[root] != NULL && parent.find(parent[root]) != parent.end() && parent[parent[root]] != NULL){
        if(parent[parent[root]]->val %2 == 0){
            ans = ans + root->val;
        }
    }
    solve(root->left,parent,ans);
    solve(root->right,parent,ans);


}
public:
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> parent;
        getparent(root,parent);
        int ans = 0;
        solve(root,parent,ans);
        return ans;
    }
};