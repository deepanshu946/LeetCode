class Solution {
private:
int solve(vector<vector<int>>&tri){
    vector<vector<int>> dp(tri.size()+1 , vector<int>(tri.back().size()+1 , 0));
    for(int row = tri.size()-1 ; row>=0 ; row--){
        for(int index = row ; index>=0 ; index--){
            int same = dp[row+1][index];
            int plus = dp[row+1][index+1];
            dp[row][index]=tri[row][index] + min(same,plus);
        }
    }
    return dp[0][0];
    
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle);
    }
};