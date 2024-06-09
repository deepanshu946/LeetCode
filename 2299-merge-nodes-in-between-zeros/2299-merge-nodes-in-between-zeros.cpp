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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* temp = head->next;
        ListNode* ans = NULL;
        int sum = 0;
        while(temp != NULL){
            if(temp->val == 0){
                ListNode* temp2 = new ListNode(sum);
                if(newhead != NULL){

                    newhead->next = temp2;
                    newhead = newhead->next;
                }
                else{
                    newhead = temp2;
                    ans = newhead;
                }
                sum = 0;
            }
            sum = sum + temp->val;
            temp = temp->next;
        }
        newhead->next = NULL;
        return ans;
    }
};