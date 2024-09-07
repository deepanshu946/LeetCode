class Solution {
public:
    bool solve(ListNode*head,TreeNode*root){
        ListNode*temp=head;
        if(temp->next==NULL) return true;
        if(root==NULL) return false;
        bool ans1=false,ans2=false;
        if(temp!=NULL && root->val==temp->val){
            temp=temp->next;
            if(temp && root->left && temp->val==root->left->val)
                ans1=solve(temp,root->left);
            if(temp && root->right && temp->val==root->right->val)
                ans2=solve(temp,root->right);
        }
        return ans1 || ans2;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL) return false;
        if(solve(head,root)) return true;
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};