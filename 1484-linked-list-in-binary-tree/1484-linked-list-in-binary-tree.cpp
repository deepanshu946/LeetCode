/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
bool check(ListNode* head , TreeNode* root){
    if(head->next==NULL && root->val==head->val){
        return 1;
    }
    if(root==NULL){
        return 0;
    }
    if(head->val != root->val ){
        return 0;
    }
    // ListNode* temp = head;
    // TreeNode* roottemp = root;
    bool ans = 0;
        
        if( root->right != NULL){
            ans = ans | check(head->next,root->right);
        }
        if(root->left != NULL){
            ans = ans | check(head->next,root->left);
        }
        return ans;
    }
bool gethead(ListNode* head , TreeNode* root){
    if(root==NULL){
        return 0;
    }
    bool ans = 0;
    if(head->val == root->val){
        ans = ans | check(head,root);
    }
    ans = ans | gethead(head , root->left);
    ans = ans | gethead(head,root->right);
    return ans;
}
public:
    bool isSubPath(ListNode* head, TreeNode* root){
        return gethead(head , root);
    }
};