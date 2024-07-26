class Solution {
private:
// int solve(int i,int j , string s1 , string s2){
//     if(i==s1.length() && j==s2.length()){
//         return 0;
//     }
//     else if(i==s1.length() && j<s2.length()){
//         int ans = 0;
//         for(int k=j ; k<s2.length() ; k++){
//             ans = ans + s2[k];
//         }
//         return ans;
//     }
//     else if(j==s2.length() && i<s1.length()){
//         int ans = 0;
//         for(int k=i ; k<s1.length() ; k++){
//             ans = ans + s1[k];
//         }
//         return ans;
//     }
//     int ans = 0;
//     if(s1[i]==s2[j]){
//         ans = solve(i+1,j+1,s1,s2);
//     }
//     else{
//         ans =min(s1[i]+solve(i+1,j,s1,s2) ,s2[j]+solve(i,j+1,s1,s2));
//     }
//     return ans;
// }
public:
    int minimumDeleteSum(string s1, string s2) {
        // return solve(0,0,s1,s2);
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int j=0 ; j<s2.length() ; j++){
            int ans = 0;
            for(int k=j ; k<s2.length() ; k++){
                ans = ans + s2[k];
            }
            dp[m][j]= ans;
        }

        for(int i=0 ; i<s1.length() ; i++){
            int ans = 0;
            for(int k=i ; k<s1.length() ; k++){
                ans = ans + s1[k];
            }
            dp[i][n]=ans;
        }
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                int ans = 0;
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] =min(s1[i]+dp[i+1][j] ,s2[j]+dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};