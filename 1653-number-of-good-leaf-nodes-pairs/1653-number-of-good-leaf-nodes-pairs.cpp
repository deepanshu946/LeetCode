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
unordered_set<TreeNode*> s;
void getparent(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &m){
    if(root==NULL){
        return ;
    }
    if(root->left != NULL){
        m[root->left]=root;
    }
    if(root->right != NULL){
        m[root->right]=root;
    }
    getparent(root->left,m);
    getparent(root->right,m);

}
int getcount(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &m , int dist , int count){
    if(root==NULL || count>dist){
        return 0;
    }
    if(root->left==NULL && root->right==NULL && count>0 && count<=dist){
        return 1;
    }
    s.insert(root);
    //make 3 calls
    int parent = 0;
    int left=0;
    int right = 0;
    if(m.find(root) != m.end() && s.find(m[root]) == s.end()){
        parent = getcount(m[root],m,dist,count+1);
    }
    if(s.find(root->left)==s.end()){
        left=getcount(root->left,m,dist,count+1);
    }
    if(s.find(root->right ) == s.end()){
        right = getcount(root->right,m,dist,count+1);
    }
    s.erase(root);
    return left+right+parent;


}


int solve(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &m , int dist){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return getcount(root,m,dist,0);
    }
    return solve(root->left,m,dist)+solve(root->right,m,dist);
}
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*> m;
        getparent(root,m);
        m[root]=NULL;
        return solve(root,m,distance)/2;
    }
};