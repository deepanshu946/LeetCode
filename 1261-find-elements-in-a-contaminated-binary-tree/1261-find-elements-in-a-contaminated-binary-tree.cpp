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
class FindElements {
public:
    unordered_map<TreeNode* , TreeNode*> parent;
    unordered_set<int> s;
    // TreeNode* root1=NULL;
    void makechanges(TreeNode* root,unordered_set<int> &s ){
        if(root==NULL){
            return;
        }
        if(root->left != NULL){
            root->left->val = (2*root->val)+1;
            s.insert((2*root->val)+1);
        }
        if(root->right != NULL){
            root->right->val = (2*root->val)+2;
            s.insert((2*root->val)+2);
        }
        makechanges(root->left,s);
        makechanges(root->right,s);

    }
    
    FindElements(TreeNode* root) {
        // root1=root;
        root->val=0;
        s.insert(0);
        makechanges(root,s);

    }
    
    bool find(int target) {
        if(s.find(target) != s.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */