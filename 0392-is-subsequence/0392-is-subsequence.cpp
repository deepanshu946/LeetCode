class Solution {
private:
bool solve(string s , string t , int i , int j){
    // vector<vector<bool>> dp(s.length()+1 , vector<bool>(t.length()+1,0));
    vector<bool> curr(t.length()+1 , 0);
    vector<bool> prev(t.length()+1 , 1);
    // for(int i=0 ; i<=t.length() ; i++){
    //     dp[s.length()][i]=1;
    // }
    for(int i=s.length()-1 ; i>=0 ; i--){
        for(int j=t.length()-1 ; j>=0 ; j--){
            if(s[i]==t[j]){
                curr[j]= prev[j+1];
            }
            else{
                curr[j] = curr[j+1];
            }
        }
        prev = curr;
    }
    return prev[0];
}
public:
    bool isSubsequence(string s, string t) {
        return solve(s,t,0,0);
    }
};