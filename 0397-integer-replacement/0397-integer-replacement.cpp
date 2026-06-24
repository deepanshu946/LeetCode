class Solution {
private:
// int solve(int n, vector<int> dp){
    
//     if(n==1){
//         return 0;
//     }
//     if(dp[n] != -1){
//         return dp[n];
//     }
    
//     if(n%2==0){
//         return dp[n]= 1+solve(n/2,dp);
//     }
//     else{
//         return dp[n]= 1+min(solve(n+1,dp),solve(n-1,dp));
//     }
// }
public:
    int integerReplacement(int n) {
        // vector<int> dp(n+2,-1);
        if(n == 2147483647){
        return 32;
        }
        int ans = 0;
        while(n != 1){
            if(n%2==0){
                n=n/2;
            }
            else if(n==3 || (n-1) %4==0){
                n=n-1;
            }
            else{
                n=n+1;
            }
            ans++;
        }
        return ans;
    }
};