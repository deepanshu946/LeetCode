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
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = curr;
        ListNode* ans = head->next;
        while(curr != NULL && curr->next != NULL){
            nex = curr->next;
            curr->next = nex->next;
            nex->next = curr;
            if(prev != NULL){
                prev->next = nex;
            }
            prev = curr;
            curr=curr->next;
        }
        return ans;
    }
};