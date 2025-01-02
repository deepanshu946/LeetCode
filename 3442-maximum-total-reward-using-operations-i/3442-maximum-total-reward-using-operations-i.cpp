class Solution {
private:
int solve(int i , vector<int>&nums , int n , int curr , map<pair<int,int> , int>  &dp){
    if(i>=n){
        return 0;
    }

    if(curr >= 2e3){
        return 0;
    }
    if(dp.find({i,curr}) != dp.end()){
        return dp[{i,curr}];
    }
    int inc = 0;
    if(nums[i]>curr){
        inc = nums[i] + solve(i+1,nums,n,curr+nums[i],dp);
    }
   int  exc = solve(i+1,nums,n,curr,dp);
    return dp[{i,curr}]= max(inc , exc);
}
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());

        // vector<int> dp(nums.size(),-1);
        map<pair<int,int> , int > dp;
        return solve(0,nums,nums.size(),0,dp);
    }
};