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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode* , int> m;
        queue<TreeNode*> q;
        unordered_map<TreeNode* , TreeNode*> parent;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> temp;
            for(int i=0 ; i<size ; i++){
                TreeNode* front=q.front();
                q.pop();
                temp.push_back(front);
                if(front->left){
                    q.push(front->left);
                    parent[front->left]=front;
                }
                if(front->right){
                    q.push(front->right);
                    parent[front->right]=front;
                }
            }
            int sum = 0;
            for(int i=0 ; i<temp.size() ; i++){
                sum = sum + temp[i]->val;
            }
            for(int i=0 ; i<temp.size() ; i++){
                TreeNode* p = parent[temp[i]];
                int minus = temp[i]->val;

                if(i-1>=0 && parent[temp[i-1]] == parent[temp[i]]){
                    minus = minus + temp[i-1]->val;
                }
                if(i+1<temp.size() && parent[temp[i+1]] == parent[temp[i]]){
                    minus = minus + temp[i+1]->val;
                }

                m[temp[i]]=sum-minus;
            }
        }
        for(auto &i:m){
            i.first->val=i.second;
        }
        return root;


    }
};