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
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
  int n1 = arr1.size();
  int n2 = arr2.size();

  // Create a new array to store the merged result
  vector<int> arr3(n1 + n2);
  int i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      arr3[k] = arr1[i];
      i++;
    } else {
      arr3[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr3[k] = arr1[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr3[k] = arr2[j];
    j++;
    k++;
  }
  return arr3;
}
void inorder(TreeNode* root , vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right , ans);
}
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sort1;
        vector<int>sort2;
        inorder(root1 , sort1);
        inorder(root2 , sort2);
        return mergeArrays(sort1,sort2);
    }
};