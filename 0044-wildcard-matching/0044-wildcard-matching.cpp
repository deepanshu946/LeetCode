class Solution {
private:
bool solve(string &s , string &p){
    vector<vector<bool>> dp(s.length()+1 , vector<bool>(p.length()+1,0));
    dp[0][0]=1;
        for(int j=1 ; j<=p.length() ;j++){
            bool check =1;
            for(int k=1 ; k<=j ; k++){
            if(p[k-1]!='*'){
                check = 0;
                break;
            }
        }
        dp[0][j] = check;
    }
    for(int i=1 ; i<=s.length() ; i++){
        for(int j=1 ; j<=p.length() ; j++){
            //match
            if(s[i-1]==p[j-1] || p[j-1]=='?'){
                dp[i][j]= dp[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                bool empty=dp[i][j-1];
                bool replace=dp[i-1][j];
                dp[i][j]= empty||replace;
            }
            else{
                dp[i][j] =false;
            }
        }
    }
    return dp[s.length()][p.length()];
}
public:
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};



//recursion
// bool solve(string &s , string &p , int i  , int j){
//     if(i<0 && j<0){
//         return true;
//     }
//     if(i>=0 && j<0){
//         return false;
//     }
//     if(i<0 && j>=0 ){
//         for(int k=0 ; k<=j ; k++){
//             if(p[k]!='*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     //match
//     if(s[i]==p[j] || p[j]=='?'){
//         return solve(s,p,i-1,j-1);
//     }
//     else if(p[j]=='*'){
//         bool empty=solve(s,p,i,j-1);
//         bool replace=solve(s,p,i-1,j);
//         return empty||replace;
//     }
//     else{
//         return false;
//     }
// }