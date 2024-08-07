class Solution {
private:
int solve( int n , string &s){
    // if(start>end){
    //     return 0;
    // }
    
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> curr(n+1,0);
    vector<int> prev(n+1,0);
    for(int start = n-2 ; start>=0 ; start--){
        for(int end = start+1 ; end < n ; end++){
        if(s[start]==s[end]){
            prev[end]= curr[end-1];
            }
            else{
                prev[end]= min(1+curr[end] , 1+prev[end-1]);
            }
        }
        curr = prev;
    }
    return curr[n-1];

}
public:
    int minInsertions(string s) {
        int n = s.length();
        return solve(n,s);
    }
};