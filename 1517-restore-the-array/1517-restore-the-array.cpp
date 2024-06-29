class Solution {
private:
#define mod 1000000007
int solve(string &s, int k){
    vector<int> dp(s.length()+5 , 0);
    dp[s.length()]=1;
    for(int i=s.length()-1 ; i>=0 ; i--){
        long long ans =0;
        long long num=0;
        for(int j=i ; j<s.length() ; j++){
            num=((num)*10 + (s[j]-48));
            if(num==0 || num>k){
                break;
            }
            if(num<=k){
                ans=(ans+dp[j+1])%mod;
            }
        }
        dp[i]= ans%mod;
    }
    return dp[0];
}
public:
    int numberOfArrays(string s, int k) {
        return solve(s,k);
    }
};