class Solution {
private:
long long solve(int i , vector<int> &nums , bool even){
    if(i>=nums.size()){
        return 0;
    }
    long long inc ;
    long long exc;
    if(even){
        inc = nums[i]+solve(i+1,nums,!even);
        
    }
    else{
        inc = -nums[i]+solve(i+1,nums,!even);
    }
    exc = solve(i+1,nums,even);
    return max(inc , exc);

}
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // return solve(0,nums,1);
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,0));

        for(int i=nums.size()-1 ; i>=0 ; i--){
            for(int even = 0 ; even<=1 ; even++){
                long long inc ;
                long long exc;
                if(even){
                    inc = nums[i]+dp[i+1][!even];
                    
                }
                else{
                    inc = -nums[i]+dp[i+1][!even];
                }
                exc = dp[i+1][even];
                dp[i][even]= max(inc , exc);

            }
        }
        return dp[0][1];
    }
};