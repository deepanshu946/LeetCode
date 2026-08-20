class Solution {
private:
long long solve(int i , vector<int> &nums , vector<int> &colors){
    if(i>=nums.size()){
        return 0;
    }
    long long inc;
    if(i+1<nums.size() && colors[i+1]==colors[i]){
        inc = nums[i] + solve(i+2,nums,colors);
    }
    else{
        inc = nums[i] + solve(i+1,nums,colors);
    }
    long long exc = solve(i+1,nums,colors);
    return max(inc , exc);
}
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        // int prevcolor = -1;
        vector<long long> dp(nums.size()+2 , 0);
        for(int i=nums.size()-1 ; i>=0 ; i--){
            long long inc;
            if(i+1<nums.size() && colors[i+1]==colors[i]){
                inc = nums[i] + dp[i+2];
            }
            else{
                inc = nums[i] + dp[i+1];
            }
            long long exc = dp[i+1];
            dp[i]= max(inc , exc);
        }
        return dp[0];
        // return solve(0,nums,colors);
    }
};