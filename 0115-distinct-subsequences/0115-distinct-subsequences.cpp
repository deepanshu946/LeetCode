class Solution {
private:
int solve(string s , string t , int i , int j , vector<vector<int>> &dp){
    if(i>=s.length() && j<t.length()){
        return 0;
    }
    else if(j==t.length() && i<s.length()){
        return 1;
    }
    else if(j==t.length() && i==s.length()){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int inc = 0;
    if(s[i]==t[j]){
        inc = solve(s,t,i+1,j+1,dp);
    }
    int exc = solve(s,t,i+1,j,dp);
    dp[i][j]= inc+exc;
    return dp[i][j];


}

public:
    int numDistinct(string s, string t){
        vector<vector<int>> dp(s.length()+1 , vector<int>(t.length()+1, -1));
        return solve(s,t,0,0,dp);
    }
};