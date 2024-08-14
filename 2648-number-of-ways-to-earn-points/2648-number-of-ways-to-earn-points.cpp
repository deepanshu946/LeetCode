class Solution {
private:
#define mod 1000000007
int solve(int target , vector<vector<int>> &types ){
    // if(curr==target){
    //     return 1;
    // }
    // if(index >= types.size()){
    //     return 0;
    // }
    // if(curr>target){
    //     return 0;
    // }
    int n = types.size();
    vector<vector<int>> dp(target+1,vector<int>(n+1,0));
    //add bc to dp
    for(int i=0 ; i<=n ; i++){
        dp[target][i]=1;
    }
    for(int curr=target-1 ; curr>=0 ; curr--){
        for(int index = n-1 ; index>=0 ; index--){
            int questions = types[index][0];
            int marks = types[index][1];
            int ans = 0;
            for(int i=0 ; i<=questions ; i++){
                if(curr+(i*marks) <= target){
                    ans = (ans + (dp[curr+(i*marks)][index+1])%mod)%mod;
                }
                
            }
            dp[curr][index]= ans%mod;
        }
    }
    return dp[0][0];
    
    
}
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        return solve(target,types);
    }
};