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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long size = q.size();
            long long sum = 0;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                sum = sum + front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            pq.push(sum);
        }
        for(int i=0 ; i<k-1; i++){
            
            pq.pop();
            if(pq.empty()){
                return -1;
            }
        }

        return pq.top();
    }
};