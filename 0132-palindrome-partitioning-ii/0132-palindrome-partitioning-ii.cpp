class Solution {
private:
// bool check(int i , int j , string&s){
//     while(i<=j){
//         if(s[i] != s[j]){
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;
// }
vector<vector<bool>> pal; // we will compute isPalindrome! in advance because
                          // iske kaaran tle aaraha!

void precomputePalindromes(string& s, int n) {
    pal.assign(n, vector<bool>(n, false));
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2)
                    pal[i][j] = true;
                else
                    pal[i][j] = pal[i + 1][j - 1];
            }
        }
    }
}
// int solve(int i , int j , string &s){
//     if(i>=j){
//         return 0;
//     }
//     if(check(i,j,s)){
//         return 0;
//     }
//     int ans = 1e9;
//     for(int k=i ; k<j ; k++){
//         ans = min(ans ,1+ solve(i,k,s) + solve(k+1,j,s));
//     }
//     return ans;
// }
public:
    int minCut(string s) {
        // return solve(0,s.length()-1,s);
        precomputePalindromes(s,s.length());
        vector<int> dp(s.length()+1,0);

        for(int i=s.length()-1 ; i>=0 ; i--){
            int ans = 1e9;
            for(int j=i ; j<s.length() ; j++){
                
                // for(int k=i ; k<j ; k++){
                    if(pal[i][j]){
                        ans = min(ans ,1+ dp[j+1]);
                    }
                    
                // }
                dp[i]=ans;
            }
        }
        return dp[0]-1;

    }
};