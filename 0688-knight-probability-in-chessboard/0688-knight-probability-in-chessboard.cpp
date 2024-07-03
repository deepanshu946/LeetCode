class Solution {
private:
double solve(int n , int k , int i , int j,vector<vector<vector<double>>>& dp,int row , int col){
    if(i>=n || i<0 || j>=n || j<0){
        return 0;
    }
    if(k==0){
        if(i==row && j==col){
            return 1;
        }
        else{
            return 0;
        }
            
    }
    if(dp[k][i][j] != -1){
        return dp[k][i][j];
    }
    double ans = 0;
    ans = ans + solve(n,k-1,i-2,j+1,dp,row,col)/8;
    ans = ans + solve(n,k-1,i-1,j+2,dp,row,col)/8;
    ans = ans + solve(n,k-1,i+1,j+2,dp,row,col)/8;
    ans = ans + solve(n,k-1,i+2,j+1,dp,row,col)/8;
    ans = ans + solve(n,k-1,i+2,j-1,dp,row,col)/8;
    ans = ans + solve(n,k-1,i+1,j-2,dp,row,col)/8;
    ans = ans + solve(n,k-1,i-1,j-2,dp,row,col)/8;
    ans = ans + solve(n,k-1,i-2,j-1,dp,row,col)/8;
    dp[k][i][j]= ans;
    return dp[k][i][j];

}

public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1 , vector<vector<double>>(n+3 , vector<double>(n+3,-1)));
        double ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                ans = ans + solve(n,k,i,j,dp,row,column);
            }
        }        
        return ans;
        
    }
};