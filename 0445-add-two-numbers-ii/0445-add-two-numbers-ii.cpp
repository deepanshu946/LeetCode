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
    ListNode* curr = head;
    ListNode* next = curr->next;
    ListNode* prev = NULL;
    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next != NULL)
            next = next->next;

    }
    return prev;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* temp = l1;
        while(temp != NULL){
            s1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL){
            s2.push(temp->val);
            temp = temp->next;
        }
        int rem = 0;
        // ListNode* curr = NULL;
        // ListNode* next = NULL;
        ListNode* newhead = new ListNode(-1);
        temp = newhead;
        while(!s1.empty() && !s2.empty()){
            int t1 = s1.top();
            s1.pop();
            int t2 = s2.top();
            s2.pop();
            int sum = t1+t2+rem;
            rem = sum/10;
            sum = sum % 10;
            // ListNode* temp = new ListNode*(sum);
            // temp->next = next;
            // next = temp;
            if(temp->val == -1){
                temp->val = sum;
            }
            else{
                ListNode* temp2 = new ListNode(sum);
                temp->next = temp2;
                temp = temp->next;
            }
        }
        while(!s1.empty()){
            int t1 = s1.top();
            s1.pop();
            // int t2 = s2.top();
            // s2.pop();
            int sum = t1+rem;
            rem = sum/10;
            sum = sum % 10;
            // ListNode* temp = new ListNode*(sum);
            // temp->next = next;
            // next = temp;
            if(temp->val == -1){
                temp->val = sum;
            }
            else{
                ListNode* temp2 = new ListNode(sum);
                temp->next = temp2;
                temp = temp->next;
            }
        }
        while(!s2.empty()){
            // int t1 = s1.top();
            // s1.pop();
            int t2 = s2.top();
            s2.pop();
            int sum = t2+rem;
            rem = sum/10;
            sum = sum % 10;
            // ListNode* temp = new ListNode*(sum);
            // temp->next = next;
            // next = temp;
            if(temp->val == -1){
                temp->val = sum;
            }
            else{
                ListNode* temp2 = new ListNode(sum);
                temp->next = temp2;
                temp = temp->next;
            }
        }
        if(rem != 0){
             ListNode* temp2 = new ListNode(rem);
                temp->next = temp2;
                temp = temp->next;
        }
       return reverse(newhead);
        // return newhead;

        
    }
};