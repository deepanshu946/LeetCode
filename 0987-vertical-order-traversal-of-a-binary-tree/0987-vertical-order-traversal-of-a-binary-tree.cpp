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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> pq; // hd , level
        pq.push({root,{0,0}});
        int level=0;

        while(!pq.empty()){
            int size = pq.size();
            for(int i=0 ; i<size ; i++){
                auto it = pq.front();
                TreeNode* curr = it.first;
                int d = it.second.first;
                int lev = it.second.second;
                pq.pop();
                m[it.second.first][it.second.second].push_back(it.first->val);
                if(curr->left){
                    pq.push({curr->left,{d-1,lev+1}});
                }
                if(curr->right){
                    pq.push({curr->right,{d+1,lev+1}});
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> temp;
            for(auto j:i.second){
                vector<int> arr = j.second;
                sort(arr.begin(),arr.end());
                for(auto k:arr){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};