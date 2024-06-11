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
void getinorder(TreeNode* root , vector<int> &inorder){
    if(root==NULL){
        return;
    }
    getinorder(root->left,inorder);
    inorder.push_back(root->val);
    getinorder(root->right , inorder);
}
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
        getinorder(root,inorder);
        int min = INT_MAX;
        for(int i=1 ; i<inorder.size() ; i++){
            if(inorder[i]-inorder[i-1] < min){
                min = inorder[i]-inorder[i-1];
            }
        }
        return min;

    }
};