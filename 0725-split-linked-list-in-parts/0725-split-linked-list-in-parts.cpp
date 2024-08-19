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
int getlength(ListNode* temp){
    int count=0;
    ListNode* head = temp;
    while(head != NULL){
        head=head->next;
        count++;
    }

    return count;

}
pair<ListNode*,ListNode*> solve(ListNode* temp , int k){
    ListNode* prev = NULL;
    ListNode* nex = temp;
    while(k-- && nex!=NULL){
        prev = nex;
        nex = nex->next;
        
    }
    return {prev,nex};
}
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getlength(head);
        int mod = n%k;
        int div = n/k;
        ListNode* temp = head;
        vector<ListNode*> ans;
        int tempmod = mod;
        cout<<mod<<endl<<div<<endl;
        while(mod--){
            ListNode* newhead = temp;
            if(temp==NULL){
                ans.push_back(NULL);
            }
            else{
                pair<ListNode*,ListNode*> p=solve(temp,div+1);
                p.first->next = NULL;
                ans.push_back(newhead);
                temp = p.second;
            }
            
        }
        int left = k-tempmod;
        while(left--){
            ListNode* newhead = temp;
            if(temp==NULL){
                ans.push_back(NULL);
            }
            else{
                pair<ListNode*,ListNode*> p=solve(temp,div);
                p.first->next = NULL;
                ans.push_back(newhead);
                temp = p.second;
            }
        }
        return ans;


    }
};