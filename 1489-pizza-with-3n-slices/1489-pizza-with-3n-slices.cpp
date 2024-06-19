class Solution {
private:
int solve(vector<int> &slices , int start , int end , int n,vector<vector<int>> &dp){
    if(start>end || n== 0){
        return 0;
    }
    if(dp[start][n] != -1){
        return dp[start][n];
    }
    int inc = slices[start]+solve(slices,start+2,end,n-1,dp);
    int exc = solve(slices,start+1,end,n,dp);
    dp[start][n]= max(inc,exc);
    return dp[start][n];
}
public:

    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        int n = size/3;
        vector<vector<int>> dp1(size,vector<int>(n+1,-1));
        int case1=solve(slices,1,size-1,n,dp1);
        vector<vector<int>> dp2(size,vector<int>(n+1,-1));
        int case2=solve(slices,0,size-2,n,dp2);
        return max(case1,case2);
    }
};