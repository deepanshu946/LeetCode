class Solution { 
private:
int solve(vector<int> &s , int n){
    vector<vector<int>> dp(n+1,vector<int>(n+2,0));
    for(int time = n ; time>=1 ; time--){
        for(int index = n-1 ; index>=0 ; index--){
            int inc = s[index]*(time) + dp[index+1][time+1];
            int exc = dp[index+1][time];
            dp[index][time]=max(inc,exc);
        }
    }
    return dp[0][1];
}
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin() , satisfaction.end());
        return solve(satisfaction,n);
    }
};