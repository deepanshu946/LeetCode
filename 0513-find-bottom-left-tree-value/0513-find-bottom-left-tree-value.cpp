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
int curr = -1;
void solve(TreeNode* root , int &ans ,int level){
    if(root==NULL){
        return;
    }
    if(level>curr){
        ans = root->val;
        curr=level;
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
    
}
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        int level = 0;
        // solve(root,ans,level);
        // return ans;
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