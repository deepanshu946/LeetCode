class Solution {
private:
int solve(string a , string b){
    vector<vector<int>> dp(a.length()+1 , vector<int>(b.length()+1 , 0));

    // if(i==a.length() || j>b.length()){
    //     return 0;
    // }
    for(int i=a.length()-1 ; i>=0 ; i--){
        for(int j=b.length()-1 ; j>=0 ; j--){
            if(a[i]==b[j]){
                dp[i][j]= 1+dp[i+1][j+1];
            }
            else{
                dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2);
    }
};



//recursion
int solverec(string a , string b , int i , int j){
    if(i==a.length() || j>b.length()){
        return 0;
    }
    if(a[i]==b[j]){
        return 1+solverec(a,b,i+1,j+1);
    }
    else{
        return max(solverec(a,b,i+1,j),solverec(a,b,i,j+1));
    }
}