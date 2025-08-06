/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* curr = head;
        while(curr != NULL){
            m[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        Node* newhead = m[curr];
        while(curr != NULL){
            m[curr]->next = m[curr->next];
            m[curr]->random = m[curr->random];
            curr = curr->next;
        }
        return newhead;
    }
};