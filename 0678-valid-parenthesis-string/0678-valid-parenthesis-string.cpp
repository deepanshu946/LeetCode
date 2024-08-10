class Solution {
private:
int dp[102][102];
bool solve(string s , int index , int left){
    if(left<0){
        return false;
    }
    if(left==0 && index==s.length()){
        return true;
    }
    if(left!=0 && index==s.length()){
        return false;
    }
    if(dp[index][left] != -1){
        return dp[index][left];
    }
    bool ans = 0;
    if(s[index]=='('){
       ans = ans | solve(s,index+1,left+1);
    }
    if(s[index]==')'){
        ans = ans | solve(s,index+1,left-1);
    }
    if(s[index]=='*'){
        ans = ans | solve(s,index+1,left+1) | solve(s,index+1,left-1) | solve(s,index+1,left);
    }
    return dp[index][left]= ans;
}
public:
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
        
    }
};