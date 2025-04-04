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
int getdeepest(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(getdeepest(root->left),getdeepest(root->right));
}
void getcount(TreeNode* root , int temp , int curr , int &count){
    if(root==NULL){
        return;
    }
    if(curr==temp){
        count++;
    }
    getcount(root->left,temp , curr+1,count);
    getcount(root->right,temp , curr+1,count);

}
int solve(TreeNode* root , int curr , TreeNode* &ans , int temp , int count){
    if(root==NULL){
        return 0;
    }
    if(curr==temp && root->left==NULL && root->right==NULL){
        if(count==1){
            ans = root;
        }
        return 1;
    }
    int t = solve(root->left,curr+1,ans,temp,count)+solve(root->right,curr+1,ans,temp,count);
    if(t==count && ans == NULL){
        ans=root;
    }
    return t;


}
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int temp = 0;
        temp = getdeepest(root);
        temp--;
        int count=0;
        getcount(root,temp ,0 , count);
        cout<<count<<endl;
        TreeNode* ans = NULL;
        solve(root,0,ans,temp,count);
        return ans;

    }
};
