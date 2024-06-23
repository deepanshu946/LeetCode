class Solution {
private:
int solve(string a , string b){
    // vector<vector<int>> dp(a.length()+1 , vector<int>(b.length()+1 , 0));
    vector<int> curr(b.length()+1 , 0);
    vector<int> prev(b.length()+1 , 0);
    for(int i=a.length()-1 ; i>=0 ; i--){
        for(int j=b.length()-1 ; j>=0 ; j--){
            if(a[i]==b[j]){
                curr[j]= 1+prev[j+1];
            }
            else{
                curr[j]= max(prev[j],curr[j+1]);
            }
        }
        prev = curr;
    }
    return prev[0];
}
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        return solve(s,rev);
    }
};  