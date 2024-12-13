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
int getlength(ListNode* head){
    ListNode* temp = head;
    int count=0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int solve(ListNode* l1 , ListNode* l2 , vector<int> &ans){
    if(l1==NULL && l2==NULL){
        return 0;
    }
    int carry = solve(l1->next , l2->next ,ans);
    int temp = l1->val + l2->val + carry;
    int c=temp/10;
    temp = temp%10;
    ans.push_back(temp);
    return c;

}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getlength(l1);
        int len2 = getlength(l2);
        cout<<len1<<" "<<len2<<endl;
        int diff = abs(len1-len2);
        if(diff != 0){
            ListNode* newhead = new ListNode();
            ListNode* ptr = newhead;
            diff--;
            while(diff != 0){
                ListNode* temp = new ListNode();
                newhead->next = temp;
                newhead=newhead->next;
                diff--;
            }
            if(len1<len2){
                newhead->next = l1;
                l1=ptr;
            }
            else{
                newhead->next = l2;
                l2=ptr;
            }
        }
        vector<int> ans;
        int carry = solve(l1,l2,ans);
        if(carry != 0){
            ans.push_back(carry);

        }
        reverse(ans.begin(),ans.end());
        ListNode* tem = new ListNode(ans[0]);
        ListNode* an = tem;
        for(int i=1 ; i<ans.size() ; i++){
            ListNode* next = new ListNode(ans[i]);
            tem->next = next;
            tem=tem->next;
        }
        return an;
    }
};