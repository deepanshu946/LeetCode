class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i<nums.size()-2 ; i++){
            int start = i+1;
            int end = nums.size()-1;
            int val = -nums[i];
            if(i>0 && nums[i]==nums[i-1])continue;
            while(start<end){
                if(nums[start]+nums[end]==val){
                    while(start < end && nums[start] == nums[start+1])
                        start++;
                    while(start < end && nums[end] == nums[end-1])
                        end--;
                        
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end] < val){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
    }
};