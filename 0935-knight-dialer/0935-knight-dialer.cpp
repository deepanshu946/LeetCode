#define mod 1000000007
class Solution {

private:
int solve(int curr , unordered_map<int,vector<int>> &m , int n , vector<vector<int>> &dp){
    if(n==0){
        return 1;
    }
    if(dp[curr][n] != -1){
        return dp[curr][n] %mod;
    }
    int ans = 0;
    for(auto j:m[curr]){
        ans = (ans + solve(j,m,n-1,dp))%mod;
    }
    return dp[curr][n]= ans%mod;
}
public:
    int knightDialer(int n) {
        // return 0;
        unordered_map<int,vector<int>> m;
        m[1].push_back(8);
        m[1].push_back(6);
        m[2].push_back(7);
        m[2].push_back(9);
        m[3].push_back(8);
        m[3].push_back(4);
        m[4].push_back(3);
        m[4].push_back(9);
        m[4].push_back(0);
        m[6].push_back(1);
        m[6].push_back(7);
        m[6].push_back(0);
        m[7].push_back(6);
        m[7].push_back(2);
        m[8].push_back(1);
        m[8].push_back(3);
        m[9].push_back(2);
        m[9].push_back(4);
        m[0].push_back(4);
        m[0].push_back(6);
        long long ans = 0;
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        for(int i=0 ; i<=9 ; i++){
            ans+= solve(i,m,n-1,dp)%mod;
        }
        return ans%mod;
        
    }
};