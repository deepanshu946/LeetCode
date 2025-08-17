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
// void leftv(TreeNode* root ,int level , vector<int>& ans){
//     //base case
//     if(root==NULL){
//         return;
//     }
//     if(level == ans.size()){
//         ans.push_back(root->val);
//     }
//     if(root->right){
//         leftv(root->right,level+1,ans);
//     }
//     if(root->left){
//         leftv(root->left,level+1,ans);
        
//     }

// }
public:
    vector<int> rightSideView(TreeNode* root) {
     if(root==NULL){
             return {};
         }
        map<int,int> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> t= q.front();
            q.pop();
            int level = t.second;
            TreeNode* r = t.first;
            // if(m.find(level)==m.end()){
                m[level]=r->val;
            // }
            if(r->left != NULL){
                q.push({r->left,level+1});
            }
            if(r->right != NULL){
                q.push({r->right,level+1});
            }
        }
        vector<int> ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};