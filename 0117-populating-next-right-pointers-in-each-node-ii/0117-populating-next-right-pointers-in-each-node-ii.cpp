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
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        Node* prev = NULL;
        queue<Node*> pq;
        pq.push(root);
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                Node* top = pq.front();
                pq.pop();
                if(prev != NULL){
                    prev->next = top;
                }
                prev = top;
                if(top->left != NULL){
                    pq.push(top->left);
                }
                if(top->right != NULL){
                    pq.push(top->right);
                }
            }
            prev = NULL;
        }
        return root;
    }
};