class Solution {
private:
// int dp[102][102];
bool solve(string s , int index , int left){
    // if(left<0){
    //     return false;
    // }
    // if(left==0 && index==s.length()){
    //     return true;
    // }
    // if(left!=0 && index==s.length()){
    //     return false;
    // }
    // if(dp[index][left] != -1){
    //     return dp[index][left];
    // }
    // vector<vector<int>> dp(s.length()+1 , vector<int>(s.length()+1,0));
    vector<int> curr(s.length()+1,0);
    vector<int> next(s.length()+1,0);
    next[0]=1;
    // dp[s.length()][0]=1;
    for(int index=s.length()-1 ; index>=0 ; index--){
        for(int left=s.length()-1 ; left>=0 ; left--){
            bool ans = 0;
            if(s[index]=='('){
            ans = ans | next[left+1];
            }
            if(s[index]==')'){
                if(left-1>=0)
                    ans = ans | next[left-1];
            }
            if(s[index]=='*'){
                
                ans = ans | next[left+1] ;
                if(left-1>=0)
                    ans = ans | next[left-1] ;
                ans = ans | next[left];
            }
             curr[left]=ans;
        }
        next = curr;
    }
    return curr[0];
}
public:
    bool checkValidString(string s) {
        // memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
        
    }
};