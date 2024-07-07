class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(i==0){
                if(nums[1] != nums[0] && nums[n-1] != nums[0] && nums[n-1]==nums[1]){
                    ans++;
                }
                

            }
            else if(i==n-1){
                    if(nums[0] != nums[n-1] && nums[n-2] != nums[n-1] && nums[n-2]==nums[0]){
                    ans++;
                } 

            }
            else{
                if(nums[i+1] != nums[i] && nums[i-1] != nums[i] && nums[i-1]==nums[i+1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};