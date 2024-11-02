/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    // void getparent(TreeNode* root ,unordered_map<TreeNode*,TreeNode*>&parent
    // ){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(root->left != NULL){
    //         parent[root->left]=root;
    //     }
    //     if(root->right != NULL){
    //         parent[root->right]=root;
    //     }
    //     getparent(root->left,parent);
    //     getparent(root->right,parent);
    // }
    void solve(TreeNode* temp, int& sum) {
        if (temp == NULL) {
            return;
        }
        if (temp->val % 2 == 0 && temp->left && temp->left->left)
            sum = sum + (temp->left->left->val);

        if (temp->val % 2 == 0 && temp->left && temp->left->right)
            sum = sum + (temp->left->right->val);

        if (temp->val % 2 == 0 && temp->right && temp->right->right)
            sum = sum + (temp->right->right->val);

        if (temp->val % 2 == 0 && temp->right && temp->right->left)
            sum = sum + (temp->right->left->val);
        solve(temp->left, sum);
        solve(temp->right, sum);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        // unordered_map<TreeNode*,TreeNode*> parent;
        // getparent(root,parent);
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};