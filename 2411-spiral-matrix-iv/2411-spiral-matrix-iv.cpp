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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode* temp = head;
        int colstart = 0;
        int colend = n;
        int rowstart = 0;
        int rowend = m;
        while(temp != NULL && colend>=0 && rowend>=0 && rowstart<m && colstart<n){
            for(int i=colstart ; i<colend ; i++){
                ans[rowstart][i]=temp->val;
                temp = temp->next;
                if(temp==NULL){
                break;
            }
            }
            if(temp==NULL){
                break;
            }
            for(int j=rowstart+1 ; j<rowend-1 ; j++){
                ans[j][colend-1]=temp->val;
                temp = temp->next;
                if(temp==NULL){
                break;
            }
            }
            if(temp==NULL){
                break;
            }
            for(int i=colend-1 ; i>=colstart ; i--){
                ans[rowend-1][i]=temp->val;
                temp=temp->next;
                if(temp==NULL){
                break;
            }
            }
            if(temp==NULL){
                break;
            }
            for(int j = rowend-2 ; j>= rowstart+1 ; j--){
                ans[j][colstart]=temp->val;
                temp = temp->next;
                if(temp==NULL){
                break;
            }
            }
            if(temp==NULL){
                break;
            }
            colstart++;
            colend--;
            rowstart++;
            rowend--;
        }
        return ans;

    }
};