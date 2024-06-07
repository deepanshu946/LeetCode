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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        if(root==NULL)
        return ans;
        while(!q.empty()){
            double sum = 0;
            double count =0;
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                sum = sum + front->val;
                count++;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right ){
                    q.push(front->right);
                }
            }
           
            ans.push_back(sum/count);
        }
        return ans;
    }
};