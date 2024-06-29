class Solution {
private:
int solve(string& s){
    // vector<int> dp(s.length()+2 , 0);
    int next2=0;
    int next1=1;

    // dp[s.length()]=1;
    for(int i=s.length()-1 ; i>=0 ; i--){
        int ans1=0;
        int ans2=0;
        char digit1 = s[i];
        int num = digit1-48;
        if(num != 0){
            ans1 = next1;
            char digit2 = s[i+1];
            num=10*num+(digit2-48);
            if(num>0 && num<=26){
                ans2 = next2;
            }
        }
        int curr= ans1+ans2;
        next2=next1;
        next1=curr;
    }
    return next1;
    

}
public:
    int numDecodings(string s) {
        return solve(s);
    }
};