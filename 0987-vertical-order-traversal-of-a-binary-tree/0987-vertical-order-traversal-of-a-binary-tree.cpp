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
void solve(TreeNode* root , int pos ,int level, map<pair<int,int>,vector<int>>  &m){
    if(root==NULL){
        return;
    }
     m[{pos,level}].push_back(root->val);

    solve(root->left,pos-1,level+1 , m);
    solve(root->right,pos+1,level+1,m);
}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> m;
        solve(root,0,0,m);
        vector<vector<int>> ans;
        map<int,vector<int>> m2;
        for(auto &i:m){
            // vector<int> temp;
            sort(i.second.begin(),i.second.end());
            for(auto j:i.second){
                m2[i.first.first].push_back(j);
            }
        }
        for(auto i:m2){
            ans.push_back(i.second);
        }
        return ans;

    }
};