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
void getinorder(TreeNode* root , vector<int> &in){
    if(root==NULL){
        return;
    }
    getinorder(root->left,in);
    in.push_back(root->val);
    getinorder(root->right,in);
}
void buildtree(TreeNode* root , vector<int> &greater){
    if(root==NULL){
        return;
    }
    buildtree(root->left,greater);
    root->val = greater.back();
    greater.pop_back();
    buildtree(root->right,greater);
}
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;
        getinorder(root,inorder);
        int n = inorder.size();
        for(int i=n-2 ; i>=0 ; i-- ){
            inorder[i]=inorder[i]+inorder[i+1];
        }
        reverse(inorder.begin(),inorder.end());
        buildtree(root,inorder);
        return root;
    }
};