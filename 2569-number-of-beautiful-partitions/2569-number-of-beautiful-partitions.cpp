class Solution {
private:
# define mod 1000000007
bool isprime(char ch){
    if(ch=='2' || ch=='3' || ch=='5' || ch=='7'){
        return true;
    }
    return false;
}
int solve( string s , int k , int minlen ){
    // if(k==0 && i>=s.length()){
    //     return 1;
    // }
    // if(i>=s.length()){
    //     return 0;
    // }
    if(isprime(s[s.length()-1]) || !isprime(s[0])){
        return 0;
    }
    vector<vector<int>> dp(s.length()+1,vector<int>(k+1,0));
    dp[s.length()][0]=1;
    for(int i=s.length()-1 ; i>=minlen ; i--){
        for(int k1 = 0 ; k1<=k ; k1++){
            int ans = dp[i+1][k1]%mod;
            if(i>=1 && !isprime(s[i-1]) && isprime(s[i]) && k1>0){
                if(i+minlen <= s.length()){
                    ans = (ans + dp[i+minlen][k1-1])%mod ; 
                }
            }
            dp[i][k1]= ans%mod;
        }
    }
    return dp[minlen][k-1];
}
public:
    int beautifulPartitions(string s, int k, int minlength) {
        return solve(s,k,minlength);
    }
};