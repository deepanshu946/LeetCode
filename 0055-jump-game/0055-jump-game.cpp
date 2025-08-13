class Solution {
// private:
// bool solve(int i , vector<int> &nums){
//     if(i==nums.size()-1){
//         return 1;
//     }
//     if(i>=nums.size()){
//         return 0;
//     }

//     bool ans = 0;
//     for(int jump=1 ; jump<=nums[i] ; jump++){
//         ans = ans | solve(i+jump , nums);
//     }
//     return ans;


// }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , 0);
        dp[nums.size()-1]=1;
        for(int i=nums.size()-2 ; i>=0 ; i--){
             bool ans = 0;
            for(int jump=1 ; jump<=nums[i] && i+jump<nums.size(); jump++){
                ans = ans | dp[i+jump];
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};