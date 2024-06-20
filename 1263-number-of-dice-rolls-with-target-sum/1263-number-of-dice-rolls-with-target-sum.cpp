class Solution {
#define mod 1000000007
private:
int solve(int n , int k , int target){
    vector<vector<int>> dp(n+1 , vector<int>(target+1,0));

    if(target<0){
        return 0;
    }
    dp[0][0]=1;

    for(int dice = 1 ; dice<=n ; dice++){
        for(int sum = 1 ; sum <=target ; sum++ ){
            int ans=0 ;
            for(int i=1 ; i<=k ; i++){
                if(sum-i>=0){
                    ans = (ans%mod+dp[dice-1][sum-i]%mod)%mod;
                }
            }
            dp[dice][sum]=ans%mod;
        }
    }
    return dp[n][target];


    

}
public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n,k,target);
    }
};