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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        s.insert(nums.begin() , nums.end());
        ListNode* newhead = NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            if(s.find(temp->val) == s.end()){
                if(newhead==NULL){
                    newhead= temp;
                }
                prev = temp;
            }
            else{
                if(prev != NULL){
                    prev->next = temp->next;
                }
            }
            temp = temp->next;
        }
        return newhead;
        
    }
};