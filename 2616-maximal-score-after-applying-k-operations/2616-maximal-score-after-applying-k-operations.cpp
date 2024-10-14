class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int i=0 ; i<nums.size() ; i++){
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--){
            double top = pq.top();
            pq.pop();
            ans = ans + top;
            double temp = top/3;
            pq.push(ceil(temp));
        }
        return ans;
    }
};