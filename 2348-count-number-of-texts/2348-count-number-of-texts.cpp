class Solution {
private:
#define mod 1000000007
int solve(string& s ){
    int n = s.length();
    vector<int> dp(s.length()+10,0 );
    dp[s.length()]=1;

    for(int i=s.length()-1 ; i>=0 ; i--){
        int ans1=0;
        int ans2=0;
        int ans3=0;
        int ans4=0;

        if((s[i]>=50 && s[i]<=54) || s[i]==56){
            //check 3
            char ch = s[i];
            ans1=dp[i+1]%mod;
            if( i+1 < s.length() && s[i+1] == ch){
                ans2=dp[i+2]%mod;
                if(i+2 < s.length() && s[i+2]==ch ){
                    ans3=dp[i+3]%mod;
                }
            }
        }
        else{
            char ch = s[i];
            ans1=dp[i+1]%mod;
            if(i+1 < s.length() && s[i+1] == ch){
                ans2=dp[i+2]%mod;
                if(i+2 < s.length() && s[i+2]==ch ){
                    ans3=dp[i+3]%mod;
                    if(i+3 < s.length() && s[i+3]==ch){
                        ans4=dp[i+4]%mod;
                    }
                }
            }
        }
        dp[i] = ((ans1+ans2)%mod + (ans3+ans4)%mod)%mod;
        // dp[i] = dp[i + 1] % mod; // Single key press
            
        //     if (i + 1 < n && s[i] == s[i + 1]) {
        //         dp[i] = (dp[i] + dp[i + 2]) % mod; // Two consecutive same key presses
        //     }
            
        //     if (i + 2 < n && s[i] == s[i + 1] && s[i] == s[i + 2]) {
        //         dp[i] = (dp[i] + dp[i + 3]) % mod; // Three consecutive same key presses
        //     }
            
        //     if ((s[i] == '7' || s[i] == '9') && i + 3 < n && s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3]) {
        //         dp[i] = (dp[i] + dp[i + 4]) % mod; // Four consecutive same key presses for 7 and 9
        //     }
        }

    return dp[0];
}
public:
    int countTexts(string pressedKeys) {
        return solve(pressedKeys);
    }
};