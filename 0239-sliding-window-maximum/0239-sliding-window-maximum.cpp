class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i=0 ; i<k ; i++){
            s.insert(nums[i]);
        }
        int left = 0;

        vector<int> ans;
        ans.push_back(*s.rbegin());
        for(int i=k ; i<nums.size() ; i++){
            s.erase(s.find(nums[left]));
            s.insert(nums[i]);
            left++;
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};