class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<=4){
            return 0;
        }
        return min(abs(nums[n-1]-nums[3]),min(abs(nums[0]-nums[n-4]),min(abs(nums[1]-nums[n-3]),abs(nums[2]-nums[n-2]))));

    }
};