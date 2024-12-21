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
class Solution {
private:
ListNode* FindMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast) {
            if(!fast->next) break;
            
            fast = fast->next;
            if(fast->next) {
                fast = fast->next; slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* Merge(ListNode* left, ListNode* right) {
        ListNode* temp = left;
        ListNode* temp1 = right;
        ListNode* head;
        if(left && right && left->val < right->val) head = left;
        else {head = right;}
        ListNode* store;

        while(temp && temp1) {
            if(temp1->val > temp->val) {
                store = temp->next;
                while(temp->next && temp->next->val < temp1->val) {
                    temp = temp->next;
                    store = temp->next;
                }
                temp->next = temp1;
                temp = store;
            }
            else {
                store = temp1->next;
                while(temp1->next && temp1->next->val <= temp->val) {
                    temp1 = temp1->next;
                    store = temp1->next;
                }
                temp1->next = temp;
                temp1 = store; 
            }
        }
        return head;
    }
public:
    ListNode* sortList(ListNode* head){
         //base case
        if(!head) {
            return NULL;
        }
        if(!head->next) {
            return head;
        }
        //ekk case solve krenge
        ListNode* mid = FindMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        ListNode* temp = Merge(left, right);
        return temp;
       }
    
};