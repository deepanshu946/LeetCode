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
void solve(TreeNode* root , vector<string> &temp , string s){
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        s.push_back(root->val + 'a');
        reverse(s.begin(),s.end());
        temp.push_back(s);
        s.pop_back();
        return;
    }
    s.push_back(root->val + 'a');
    solve(root->left,temp,s);
    solve(root->right , temp , s);
    s.pop_back();

}
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> temp;
        solve(root,temp,"");
        sort(temp.begin(),temp.end());
        return temp[0];
    }
};