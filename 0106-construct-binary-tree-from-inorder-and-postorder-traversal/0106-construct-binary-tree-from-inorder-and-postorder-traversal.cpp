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
    // int findpos(vector<int> in, int element) {
    //     for (int i = 0; i < in.size(); i++) {
    //         if (in[i] == element) {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    TreeNode* solve(vector<int>& in, vector<int>& post, int& index, int instart,
                    int inend, int n , unordered_map<int,int> &m) {
        // base case
        if (index < 0 || instart > inend) {
            return NULL;
        }
        int element = post[index];
        index--;
        TreeNode* root = new TreeNode(element);
        int pos = m[element];
        // call
        root->right = solve(in, post, index, pos + 1, inend, n,m);
        root->left = solve(in, post, index, instart, pos - 1, n,m);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n - 1;
        int instart = 0;
        int inend = n - 1;
        unordered_map<int,int> m;
        for(int i=0 ; i<inorder.size(); i++){
            m[inorder[i]]=i;
        }
        return solve(inorder, postorder, index, instart, inend, n, m);
        // return ans;
    }
};