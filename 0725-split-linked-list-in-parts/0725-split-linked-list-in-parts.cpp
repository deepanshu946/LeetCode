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
int getlen(ListNode* head){
    ListNode* temp = head;
    int size = 0;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return size;
}
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = getlen(head);
        int each = len/k;
        int rem = len%k;
        ListNode* start = head;
        vector<ListNode*> ans;
        while(k--){
            ListNode* newhead  =NULL;
            ListNode* temp = start;
            ListNode* prev = NULL;
            for(int i=0 ; i<each ; i++){
                prev = temp;
                temp = temp->next;
            }   
            if(rem != 0){
                prev = temp;
                temp = temp->next;
                rem--;
            }    
            if(prev==NULL){
                ans.push_back(NULL);
            }
            else{
                newhead = start;
                start = temp;
                prev->next = NULL;
                ans.push_back(newhead);

            }
        }
        return ans;

    }
};