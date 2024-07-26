class Solution {
private:
long long solve(int index , vector<vector<int>> &questions , int n){
    vector<long long> dp(n+1,0);
    for(int i=n-1 ; i>=0 ; i--){
        long long inc = 0;
        if(i+questions[i][1]+1 > n){
            inc = 0;
        }
        else{
            inc = dp[i+questions[i][1]+1];
        }
        long long exc = dp[i+1];
        dp[i] =max(questions[i][0]+inc,exc);
    }
    return dp[0];
    
}
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0,questions , questions.size());
    }
};