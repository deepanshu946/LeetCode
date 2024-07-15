/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
        unordered_map<int, TreeNode*> m;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][0];
            int child = nums[i][1];
            int left = nums[i][2];
            TreeNode* parent;
            TreeNode* temp;
            if (m.find(val) == m.end()) {
                parent = new TreeNode(val);

            } else {
                parent = m[val];
            }
            if (m.find(child) == m.end()) {
                temp = new TreeNode(child);
            } else {
                temp = m[child];
            }
            if (left == 1) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            m[val] = parent;
            m[child] = temp;
        }
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][1];
            m.erase(val);
        }
        TreeNode* ans;
        for (auto i : m) {
            ans = i.second;
        }
        return ans;
    }
};