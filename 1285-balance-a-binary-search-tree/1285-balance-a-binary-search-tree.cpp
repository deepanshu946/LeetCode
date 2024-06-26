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
void inorder(TreeNode* root , vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);

}
TreeNode* maketree( vector<int>& in , int start , int end ){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    TreeNode* newroot = new TreeNode(in[mid]);
    newroot->left = maketree(in , start , mid-1);
    newroot->right = maketree(in , mid+1 , end);
    return newroot;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        int n = in.size();
        int start = 0 ;
        int end = n-1;
        return maketree(in,start,end);
         
    }
};