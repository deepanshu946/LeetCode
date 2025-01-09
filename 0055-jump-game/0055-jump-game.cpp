class Solution {
private:
bool solve(vector<int> & nums , int n){
    vector<bool> dp(n+1 , 0);
    dp[n-1]=1;
    for(int index = n-2 ; index>=0 ; index--){
        bool ans = 0;
        for(int i=1 ; i<=nums[index] ; i++){
            if(index+i<=n){
                ans = ans || dp[index+i];
            }
            else{
                break;
            }
        }
        dp[index] = ans ;
    }
    return dp[0];
}
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums ,n);
    }
};