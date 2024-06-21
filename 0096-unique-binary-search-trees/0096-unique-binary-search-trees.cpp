class Solution {
private:
    int solve(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int num = 2 ; num<=n ; num++){
            for (int i = 1; i <= num; i++) {
                dp[num] = dp[num] + (dp[i - 1] * dp[num-i]);
            }
        }
        return dp[n];

    }

public:
    int numTrees(int n) { 
        if(n<=1){
            return 1;
        }
        return solve(n);
    
    }
};