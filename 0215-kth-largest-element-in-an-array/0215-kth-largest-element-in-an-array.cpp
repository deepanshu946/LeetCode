class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int count=0;
        for(int i=0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
            count++;
            if(count>k){
                pq.pop();
                count--;
            }
        }
        return pq.top();
    }
};