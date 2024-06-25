class Solution {
private:
int solve(vector<vector<int>>&tri){
    // vector<vector<int>> dp(tri.size()+1 , vector<int>(tri.back().size()+1 , 0));
    vector<int> curr(tri.back().size()+1 , 0);
    vector<int> prev(tri.back().size()+1 , 0);
    for(int row = tri.size()-1 ; row>=0 ; row--){
        for(int index = row ; index>=0 ; index--){
            int same = prev[index];
            int plus = prev[index+1];
            curr[index]=tri[row][index] + min(same,plus);
        }
        prev = curr;
    }
    return prev[0];
    
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle);
    }
};