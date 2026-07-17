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
void getmaxsum(TreeNode* root , unordered_map<TreeNode*,int> &maxsum , int sum){
    if(root->left==NULL && root->right==NULL){
        sum = sum + root->val;
        maxsum[root]=sum;
    }
    if(root->left != NULL){
        getmaxsum(root->left,maxsum,sum+root->val);
    }
    if(root->right != NULL){
        getmaxsum(root->right,maxsum,sum+root->val);
    }
}
int solve(TreeNode* &root , unordered_map<TreeNode* , int> &maxsum , int limit){
    if(root==NULL){
        return INT_MIN;
    }
    if(root->left==NULL && root->right==NULL){
        int val = maxsum[root];
        if(val < limit){
            root = NULL;      
        }
        return val;
    }
    int leftval = solve(root->left,maxsum , limit);
    int rightval = solve(root->right , maxsum , limit);
    if(max(leftval,rightval) < limit){
        root=NULL;
    }
    return max(leftval,rightval);
}
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        unordered_map<TreeNode*,int> maxsum;
        getmaxsum(root,maxsum,0);
        solve(root,maxsum,limit);
        return root;
    }
};