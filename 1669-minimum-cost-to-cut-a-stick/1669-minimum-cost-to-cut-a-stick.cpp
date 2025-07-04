class Solution {
private:
// int solve(int i , int j , vector<int> &cuts){
//     if(i>j){
//         return 0;
//     }
//     int ans = 1e9;
//     for(int k= i; k<=j ; k++){
//         ans = min(ans , cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts) + solve(k+1,j,cuts));
//     }
//     return ans;
// }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(),0));
        for(int i=cuts.size()-2 ; i>=1 ; i--){
            for(int j=1 ; j<=cuts.size()-2 ; j++){
                if(i>j){
                    continue;
                }
                int ans = 1e9;
                for(int k= i; k<=j ; k++){
                    ans = min(ans , cuts[j+1]-cuts[i-1] + dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]= ans;
            }
        }
        return dp[1][cuts.size()-2];
        // return solve(1,cuts.size()-2,cuts);
    }
};