/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
void iterate(unordered_map<TreeNode* , TreeNode*> &parent , TreeNode* root ){
    if(root==NULL){
        return;
    }
    if(root->left != NULL){
        parent[root->left] = root;
    }
    if(root->right != NULL){
        parent[root->right] = root;

    }
    iterate(parent , root->left );
    iterate(parent , root->right );
}
void solve(unordered_map<TreeNode*,TreeNode*> &parent , TreeNode* target , int k , int curr , vector<int> &ans , unordered_set<TreeNode*> &s){
    if(target == NULL){
        return;
    }
    if(curr==k){
        ans.push_back(target->val);
        return;
    }
    s.insert(target);
    if(!s.count(parent[target])){
        solve(parent,parent[target],k,curr+1,ans,s);
    }
    if(!s.count(target->left)){
        solve(parent,target->left ,k,curr+1,ans,s);
    }
    if(!s.count(target->right)){
        solve(parent,target->right,k,curr+1,ans,s);
    }


}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        parent[root]=NULL;
        iterate(parent,root);
        unordered_set<TreeNode*> s;

        vector<int> ans;
        solve(parent,target,k,0,ans,s);
        return ans;
    }
};