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
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* newhead = reverse(head);
        // while(newhead != NULL){
        //     cout<<newhead->val<<endl;

        //     newhead = newhead->next;
        // }
        int maxi = INT_MIN;
        ListNode* prev = NULL;
        ListNode* temp = newhead;
        while(temp != NULL){
            maxi = max(temp->val,maxi);
            if(temp->val < maxi){
                prev->next = temp->next;
                temp->next = NULL;
                temp = prev->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        ListNode* finalans = reverse(newhead);
        return finalans;
    } 
    };