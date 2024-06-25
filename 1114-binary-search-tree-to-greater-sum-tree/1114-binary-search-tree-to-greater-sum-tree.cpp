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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> inorder;
        getinorder(root,inorder);
        int n = inorder.size();
        vector<int> greater(n);
        greater[n-1]=inorder[n-1];
        for(int i=n-2 ; i>=0 ; i-- ){
            greater[i]=inorder[i]+greater[i+1];
        }
        reverse(greater.begin(),greater.end());
        buildtree(root,greater);
        return root;
    }
};