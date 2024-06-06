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
public:
    bool isCompleteTree(TreeNode* root) {
        int temp=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int count = 0;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left == NULL){
                    count++;
                }
                else{

                    if(count > 0 || temp>0){
                        return false;
                    }
                    q.push(front->left);
                }
                if(front->right == NULL){
                    count++;
                }
                else{
                    if(count > 0 || temp>0){
                        return false;
                    }
                    q.push(front->right);
                }
            }
            temp = count;
            count =0;
        }
        return true;
    }
};