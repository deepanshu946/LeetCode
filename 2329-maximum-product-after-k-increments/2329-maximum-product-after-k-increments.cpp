class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int> , greater<int>> pq;
        for(int i=0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(top+1);
        }
        long long ans =1;
        while(!pq.empty()){
            ans = ((ans)%1000000007 *( pq.top())%1000000007)%1000000007;
            pq.pop();
        }
        return ans%1000000007;
    }
};