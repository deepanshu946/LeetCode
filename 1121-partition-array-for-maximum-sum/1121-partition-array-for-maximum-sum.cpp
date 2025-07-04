class Solution {
private:
// int solve(int i , int k , vector<int> &nums){
//     if(i>=nums.size()){
//         return 0;
//     }
//     int ans = 0;
//     int maxx =0;
//     for(int j=0 ; j<k ; j++){
//         if(i+j >=nums.size()){
//             continue;
//         }

//         maxx = max( maxx , nums[i+j]);
//         ans = max(ans , ((j+1)*maxx) + solve(i+j+1,k,nums));

//     }
//     return ans;

// }
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        // return solve(0,k,nums);
        vector<int> dp(nums.size()+1 , 0);
        for(int i=nums.size()-1 ; i>=0 ; i--){
             int ans = 0;
            int maxx =0;
            for(int j=0 ; j<k ; j++){
                if(i+j >=nums.size()){
                    break;
                }

                maxx = max( maxx , nums[i+j]);
                ans = max(ans , ((j+1)*maxx) + dp[i+j+1]);

            }
            dp[i]= ans;
        }
        return dp[0];
    }
};