class Solution {
private:
int solve( int n , string &s){
    // if(start>end){
    //     return 0;
    // }
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int start = n-2 ; start>=0 ; start--){
        for(int end = start+1 ; end < n ; end++){
        if(s[start]==s[end]){
            dp[start][end]= dp[start+1][end-1];
            }
            else{
                dp[start][end]= min(1+dp[start+1][end] , 1+dp[start][end-1]);
            }
        }
    }
    return dp[0][n-1];

}
public:
    int minInsertions(string s) {
        int n = s.length();
        return solve(n,s);
    }
};