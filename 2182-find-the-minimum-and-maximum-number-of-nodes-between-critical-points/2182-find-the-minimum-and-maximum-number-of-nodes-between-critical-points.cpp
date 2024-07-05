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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2);
        vector<int> temp;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        int count = 2;
        while(curr->next != NULL){
        if((curr->val < prev->val && curr->val < curr->next->val) ||
            (curr->val > prev->val && curr->val > curr->next->val) ){
                temp.push_back(count);
            }
               
        count++;
        prev = curr;
        curr = curr->next;

        }
        if(temp.size()<2){
            ans[0] = -1;
            ans[1] = -1;
            return ans;
        }
        int min1 = 2147483646;
        for(int i=0 ; i<temp.size()-1 ; i++){
            int a = temp[i+1] - temp[i];
            min1 = min(a,min1);
        }
        int size = temp.size()-1;
        int max = temp[size]-temp[0];
        ans[0] = min1;
        ans[1] = max;
        return ans;
        
    }
};