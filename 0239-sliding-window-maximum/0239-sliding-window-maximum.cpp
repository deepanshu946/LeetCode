class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> pq;
        for(int i=0 ; i<k ; i++){
            if(pq.size()==0){
                pq.push_back(i);
            }
            else{
                while(!pq.empty() && nums[pq.back()]< nums[i]){
                    pq.pop_back();
                }
                pq.push_back(i);
            }
        }
        int left = 0;
        vector<int> ans;
        ans.push_back(nums[pq.front()]);
        int right = k;
        while(right < nums.size()){
            if(pq.front() <= left){
                pq.pop_front();
            }
            while(!pq.empty() && nums[pq.back()]< nums[right]){
                pq.pop_back();
            }
            pq.push_back(right);
            ans.push_back(nums[pq.front()]);
            right++;
            left++;
        }
        return ans;
    }
};