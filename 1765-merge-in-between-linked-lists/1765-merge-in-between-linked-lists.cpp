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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1 ;
        for(int i=0 ; i<a-1 ; i++){
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        for(int i=0 ; i<b-a ; i++){
            temp2 = temp2->next;
        }

        temp->next = list2;
        ListNode* list2head = list2;
        while(list2head->next!= NULL){
            list2head = list2head->next;
        }
        list2head->next = temp2->next;
        return list1;
    }
};