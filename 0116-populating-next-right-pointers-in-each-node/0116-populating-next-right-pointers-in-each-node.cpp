/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
void link(Node* root){
    if(root->left==NULL){
        // root->next = NULL;
        return;
    }
    root->left->next = root->right;
    link(root->left);
    if(root->next == NULL){
        root->right->next = NULL;
    }
    else{
        root->right->next = root->next->left;
    }
    link(root->right);

}
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        root->next = NULL;
        link(root);
        return root;

    }
};