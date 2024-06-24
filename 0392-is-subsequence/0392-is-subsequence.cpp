class Solution {
private:
bool solve(string s , string t , int i , int j){
    vector<vector<bool>> dp(s.length()+1 , vector<bool>(t.length()+1,0));
    for(int i=0 ; i<=t.length() ; i++){
        dp[s.length()][i]=1;
    }
    for(int i=s.length()-1 ; i>=0 ; i--){
        for(int j=t.length()-1 ; j>=0 ; j--){
            if(s[i]==t[j]){
                dp[i][j]= dp[i+1][j+1];
            }
            else{
                dp[i][j] = dp[i][j+1];
            }
        }
    }
    return dp[0][0];
}
public:
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};