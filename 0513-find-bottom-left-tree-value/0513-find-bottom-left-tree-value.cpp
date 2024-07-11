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
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        int level = 0;
        // solve(root,ans,level,0);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool check = 0;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                if(!check){
                    check = 1;
                    ans = front->val;
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};