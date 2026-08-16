class Solution {
private:
int solve(int i , vector<int> &nums , int x, vector<vector<int>> &dp){
    
    if(i>=nums.size()){
        if(x != 0){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[i][x] != -1){
        return dp[i][x];
    }
    int inc = 0;
    inc = 1+ solve(i+1 , nums , x^nums[i],dp);
    int exc = solve(i+1,nums,x,dp);
    return dp[i][x]= max(inc , exc);
}
public:
    int longestSubsequence(vector<int>& nums) {

        int temp = 0;
        int nonzero = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] != 0){
                nonzero++;
            }
            temp= temp^nums[i];
        }
        if(temp==0){
            if(nonzero ==0){
                return 0;
            }
            return nums.size()-1;
        }
        return nums.size();


        int x = 0;
        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++){
            maxi =max(maxi , nums[i]);
        }
        long long value = 1;
        while(value<=maxi)
        {
            value=value << 1;
        }
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(value+1 , -1));
        return solve(0,nums,x,dp);
        // for(int x=1 ; x<=value ; x++ ){
        //     dp[n][x]=INT_MIN;
        // }
        // for(int i=n-1 ; i>=0 ; i--){
        //     for(int x=value ; x>=0 ; x--){
        //         int inc = 1+ dp[i+1][x^nums[i]];
        //         int exc = dp[i+1][x];
        //         dp[i][x]= max(inc , exc);
        //     }
        // }
        // return dp[0][0];

        
    }
};