class Solution {
private:
 int dp[22][22][22][22];
int solve(int i,int j , int m , int n , vector<int> &hor , vector<int> &ver){
    if(i==n && j==m){
        return 0;
    }
    if (dp[i][j][m][n] != -1) {
        return dp[i][j][m][n];
    }


    int ans = INT_MAX;
    int incrow = INT_MAX;
    int inccol=INT_MAX;
    for(int start = i ; start < n ; start++){
        int cost = hor[start];
            cost += solve(i, j, m, start, hor, ver);
            cost += solve(start + 1, j, m, n, hor, ver);
            ans = min(ans, cost);
    }
    for(int start = j ; start < m ; start++){
        int cost = ver[start];
            cost += solve(i, j, start, n, hor, ver);
            cost += solve(i, start + 1, m, n, hor, ver);
            ans = min(ans, cost);
    }
    return dp[i][j][m][n]=ans;
}
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(dp, -1, sizeof(dp));
       return solve(0,0,n-1,m-1,horizontalCut,verticalCut);
    }
};