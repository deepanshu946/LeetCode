class Solution {
private:
int solve(vector<int>& nums , int n){
    vector<int> dp(n,0);

    // if(index>=n-1){
    //     return 0;
    // }
    for(int index=n-2 ; index>=0 ; index--){
        int ans = 1e9;
        for(int i=1 ; i<=nums[index];i++){
            if(index+i<n)
                ans = min(ans,1+dp[index+i]);
        }
        dp[index]=ans;
    }
    return dp[0];


}
public:
    int jump(vector<int>& nums) {
        return solve(nums,nums.size());
    }
};