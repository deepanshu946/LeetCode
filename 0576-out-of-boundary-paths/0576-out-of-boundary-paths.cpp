class Solution {
private:
#define mod 1000000007 
#define ll long long

    int solve(int m, int n, int moves, int startrow, int startcol) {
        //converting all in 1based indexing due to base cases
        vector<vector<vector<ll>>> dp(m+2 , vector<vector<ll>>(n+2 , vector<ll>(moves+1,0)));
        for(int i=0 ; i<=m+1 ; i++){
            for(int move=0 ; move<=moves ; move++){
                dp[i][0][move]=1;
                dp[i][n+1][move]=1;
            }
        }
        for(int i=0 ; i<=n+1 ; i++){
            for(int move=0 ; move<=moves ; move++){
                dp[0][i][move]=1;
                dp[m+1][i][move]=1;
            }
        }

        if (moves == 0) {
            return 0;
        }
        for(int move=1 ; move<=moves ; move++){
            for(int row=1 ; row<=m ; row++){
                for(int col=1 ; col<=n ; col++){
                    ll ans = 0;
                    ans = ans + (dp[row][col+1][move-1])%mod  +
                        (dp[row][col-1][move-1])%mod +
                        (dp[row+1][col][move-1])%mod  +
                        (dp[row-1][col][move-1])%mod ;
                    
                    dp[row][col][move]=ans%mod ;
                }
            }
        }
        return dp[startrow][startcol][moves]%mod ;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return solve(m, n, maxMove, startRow+1, startColumn+1);
    }
};