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
private:
void insertattail(Node* &head , Node* &tail , int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp != NULL){
            insertattail(clonehead , clonetail , temp->val );
            temp = temp->next;
        }
        Node* originalhead = head;
        Node* clonenode = clonehead;
        while(originalhead != NULL  && clonehead != NULL){
            Node* next = originalhead->next;
            originalhead->next = clonenode;
            originalhead= next;

            Node* next2 = clonenode->next;
            clonenode->next = originalhead;
            clonenode = next2;
        }

        originalhead = head;
        

        Node* temp2 = head;
        while(temp2 != NULL){
            if(temp2->random != NULL){
                temp2->next->random = temp2->random->next;
            }
            else{
                temp2->next->random = temp2->random;
            }
            
            temp2 = temp2->next->next;
        }
        Node* ans = clonehead;


        while(originalhead != NULL && clonehead !=NULL){
            originalhead->next = clonehead->next;
            originalhead = originalhead->next;
            if(originalhead != NULL){
            clonehead->next = originalhead->next;
            clonehead = clonehead->next;
            }
            

        }
        return ans;
    }
};