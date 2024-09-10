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
int gcd(int a , int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    if(a>=b){
        return gcd(a-b,b);
    }
    else{
        return gcd(a,b-a);
    }
}

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next ==NULL){
            return head; 
        }
        ListNode* curr = head;
        ListNode* nextnode = head;
        while(curr->next!=NULL){
            nextnode = curr->next;
            int val = gcd(curr->val , nextnode->val);
            ListNode* temp = new ListNode(val);
            curr->next = temp;
            temp->next = nextnode;
            curr=temp->next;
        }
        return head;

    }
};