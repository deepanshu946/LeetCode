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
void solve(TreeNode* root1 , TreeNode* root2 , bool &ans){
    
    if(root1 == NULL && root2 != NULL){
        cout<<"here5"<<endl;
        ans = 0;
        return;
    }
    if(root1 != NULL && root2==NULL ){
        ans = 0 ;
        cout<<"here4"<<endl;

        return;
    }
    if(root1==NULL && root2==NULL){
        cout<<"here3"<<endl;

        return;

    }
    if(ans == 0){
        cout<<"here1"<<endl;

        return;
    }
    if(root1->val != root2->val){
        cout<<"here2"<<endl;

        ans=0;
        return;
    }
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    int val4 = 0;
    if(root1->left != NULL){
        val1=root1->left->val;
    }
    if(root2->right != NULL){
        val2=root2->right->val;
    }
    if(root1->right != NULL){
        val3=root1->right->val;
    }
    if(root2->left != NULL){
        val4=root2->left->val;
    }
    if(val1 == val2 &&  val3 == val4){
        solve(root1->left,root2->right,ans);
        solve(root1->right,root2->left , ans);

    }
    else {
        cout<<root1->val<<" "<<root2->val<<endl;
        solve(root1->left,root2->left , ans);
        solve(root1->right,root2->right , ans);
    }
    

}
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans = 1;
        
        solve(root1,root2,ans);
        return ans;
    }
};