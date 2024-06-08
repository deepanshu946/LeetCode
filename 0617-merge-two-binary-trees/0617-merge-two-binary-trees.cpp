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
TreeNode* merge(TreeNode* root1 , TreeNode* root2){
    if(root1==NULL && root2==NULL){
        return NULL;
    }
    int data;
    if(root1 != NULL && root2!=NULL){
        data=root1->val + root2->val;
    }
    else if(root1 != NULL && root2==NULL){
        data = root1->val;
    }
    else{
        data = root2->val;
    }

    TreeNode* root = new TreeNode(data);
    if(root1==NULL){
        root->left = merge(root1, root2->left);
    }
    else if(root2==NULL){
        root->left = merge(root1->left , root2);
    }
    else{
        root->left = merge(root1->left , root2->left);
    }
    if(root1==NULL){
        root->right = merge(root1, root2->right);
    }
    else if(root2==NULL){
        root->right = merge(root1->right , root2);
    }
    else{
        root->right = merge(root1->right , root2->right);
    }
    return root;

}
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1 , root2);
    }
};