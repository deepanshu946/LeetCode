class Solution {
private:
int solve(string& s){
    vector<int> dp(s.length()+2 , 0);
    dp[s.length()]=1;
    for(int i=s.length()-1 ; i>=0 ; i--){
        int ans1=0;
        int ans2=0;
        char digit1 = s[i];
        int num = digit1-48;
        if(num != 0){
            ans1 = dp[i+1];
            char digit2 = s[i+1];
            num=10*num+(digit2-48);
            if(num>0 && num<=26){
                ans2 = dp[i+2];
            }
        }
        dp[i]= ans1+ans2;

    }
    return dp[0];
    

}
public:
    int numDecodings(string s) {
        return solve(s);
    }
};