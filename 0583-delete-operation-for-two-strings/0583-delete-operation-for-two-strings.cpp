class Solution {
private:
int solve( int len1 , int len2 , string &s1 , string &s2){
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
    for(int j=0 ; j<=len2 ; j++){
        dp[len1][j]=len2-j;
    }
    for(int i=0 ; i<=len1 ; i++){
        dp[i][len2]=len1-i;
    }
    for(int i=len1-1 ; i>=0 ; i--){
        for(int j=len2-1 ; j>=0 ; j--){
            if(s1[i]==s2[j]){
                dp[i][j]= dp[i+1][j+1];
            }
            else{
                dp[i][j]= 1+min(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}
public:
    int minDistance(string word1, string word2) {
        
        return solve(word1.length(),word2.length(),word1,word2);
    }
};