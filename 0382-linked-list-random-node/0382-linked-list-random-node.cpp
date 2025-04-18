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
    ListNode* myhead;
    int len=0;
    Solution(ListNode* head) {
        myhead = head;
        while(head != NULL){
            len++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int random = rand() %(len);
        ListNode* temp = myhead;
        while(random--){
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */