class Solution {
private:
#define mod 1000000007
int solve(int n , int ch , int size , vector<vector<int>> &dp){
    if(size>n){
        return 0;
    }
    if(size==n){
        return 1;
    }
    if(dp[size][ch] != -1){
        return dp[size][ch];
    }
    int ans = 0;
    if(size==0){
        ans = (ans + solve(n,0,1,dp)%mod)%mod ;
        ans = (ans + solve(n,1,1,dp)%mod) %mod;
        ans = (ans + solve(n,2,1,dp)%mod)%mod ;
        ans = (ans + solve(n,3,1,dp)%mod) %mod;
        ans = (ans + solve(n,4,1,dp)%mod )%mod;

    }
    else{
        if(ch == 0){
            ans = ans + solve(n,1,size+1,dp)%mod;
        }
        else if(ch == 1){
            ans = ans + solve(n,0,size+1,dp) + solve(n,2,size+1,dp);
        }
        else if(ch == 2){
            ans = (ans + solve(n,0,size+1,dp)% mod)%mod;
            ans = (ans +  solve(n,1,size+1,dp) %mod)%mod;
            ans = (ans +  solve(n,3,size+1,dp) %mod)%mod;
            ans = (ans +  solve(n,4,size+1,dp)%mod)%mod;
        }
        else if(ch == 3){
            ans = (ans + solve(n,2,size+1,dp)%mod+solve(n,4,size+1,dp)%mod)%mod;
        }
        else{
            ans = (ans + solve(n,0,size+1,dp))%mod;
        }
    }
    return dp[size][ch]= ans%mod;
}
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1 , vector<int>(5,-1));
        return solve(n,0,0,dp);
    }
};