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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty()){
            int size=q.size();
            int j=temp.size()-1;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                if(level%2==0){
                    if(front->left != NULL){
                        temp.push_back(front->left->val);
                    }
                    if(front->right != NULL){
                        temp.push_back(front->right->val);
                    }
                }
                if(level%2 ==1){
                    front->val = temp[j];
                    j--;
                }
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                
            }
            if(level%2==1){
                temp.clear();
            }
            
            level++;
        }
        return root;
    }
};