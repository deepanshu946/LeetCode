class Solution {
private:
#define mod 1000000007
int solve(string s , string t ){
    // vector<vector<int>> dp(s.length()+1 , vector<int> (t.length()+1,0));
    vector<int> prev(t.length()+1 , 0);
    vector<int> curr(t.length()+1 , 0);
    curr[t.length()]=1;
    prev[t.length()]=1;
    for(int i=s.length()-1; i>=0 ; i--){
        for(int j=t.length()-1 ; j>=0 ; j--){
            int inc = 0;
            if(s[i]==t[j]){
                inc = (prev[j+1])%mod;
            }
            int exc = (prev[j])%mod;
            curr[j]= (inc+exc)%mod;
        }
        prev = curr;
    }
    return prev[0];


}

public:
    int numDistinct(string s, string t){
        return solve(s,t);
    }
};