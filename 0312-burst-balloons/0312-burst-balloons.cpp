class Solution {
private:
// int solve(int i , int j , vector<int> &nums){
//     if(i>j){
//         return 0;
//     }
//     int ans = 0;
//     for(int k=i ; k<=j ; k++){
//         ans = max(ans , nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1 , nums) + solve(k+1,j,nums));
//     }
//     return ans;
// }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        // return solve(1,nums.size()-2 , nums);
        for(int i=nums.size()-2 ; i>=1 ; i--){
            for(int j=1 ; j<= nums.size()-2 ; j++){
                if(i>j){
                        continue;
                    }
                    int ans = 0;
                    for(int k=i ; k<=j ; k++){
                        ans = max(ans , nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1]+dp[k+1][j]);
                    }
                    dp[i][j]= ans;
            }
        }
        return dp[1][nums.size()-2];
        
    }
};