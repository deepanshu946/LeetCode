class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        for(int col=0 ; col<grid[0].size() ; col++){
            for(int row=1 ; row<grid.size() ; row++){
                int want = grid[row-1][col];
                int have = grid[row][col];
                if(have<=want){
                    ans = ans + want-have + 1;
                    grid[row][col]=want+1;
                }
            }
        }
        return ans;
    }
};