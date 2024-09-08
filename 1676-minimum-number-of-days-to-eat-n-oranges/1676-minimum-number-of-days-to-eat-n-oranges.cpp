class Solution {
public:
    unordered_map<int,int> dp;
    int minDays(int n){
        if(n<=1) return n;
        if(dp.find(n) != dp.end()){
            return dp[n];
        }
        dp[n]=1+min(n%2+minDays(n/2),n%3+minDays(n/3));
        return dp[n];
    }
};