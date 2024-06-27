class Solution {
private:
#define mod 1000000007
int solve(string s , string t ){
    vector<vector<int>> dp(s.length()+1 , vector<int> (t.length()+1,0));
    for(int i=0 ; i<=s.length() ; i++){
        dp[i][t.length()]=1;
    }

    for(int i=s.length()-1; i>=0 ; i--){
        for(int j=t.length()-1 ; j>=0 ; j--){
            int inc = 0;
            if(s[i]==t[j]){
                inc = (dp[i+1][j+1])%mod;
            }
            int exc = (dp[i+1][j])%mod;
            dp[i][j]= (inc+exc)%mod;
        }
    }
    return dp[0][0];


}

public:
    int numDistinct(string s, string t){
        return solve(s,t);
    }
};