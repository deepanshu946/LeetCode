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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            vector<pair<int,int>> temp;
            int size = q.size();
            int k=0;
            for(int i=0 ; i<size ; i++){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back({front->val,k});
                k++;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            sort(temp.begin(),temp.end());

            for(int i=0 ;i<temp.size() ; i++){
                if(temp[i].second == i){
                    continue;
                }
                else{
                    swap(temp[i],temp[temp[i].second]);
                    i--;
                    ans++;
                }
            }
            temp.clear();

        }
        return ans;
    }
};