class Solution {
private:
int solve(vector<vector<int>> &grid , int row , int col , int m , int n){
    vector<int> curr(n+1 , INT_MAX);
    vector<int> prev(n+1 , INT_MAX);
    if(grid[m-1][n-1]<0){
            curr[n-1] = -(grid[m-1][n-1]-1);
        }
        else{
            curr[n-1]= 1;
        }

    for(int row=m-1 ; row>=0 ; row--){
        for(int col=n-1 ; col>=0 ; col--){
            if(row==m-1 && col==n-1){
                continue;
            }
            int right = curr[col+1];
            int down = prev[col];
            int val =min(right,down)-grid[row][col];
            if(val<=0){
                curr[col]= 1;
            }
            else{
                curr[col]= val;
            }
        }
        prev = curr;
    }
    return prev[0];
    
}

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return solve(dungeon , 0 , 0 , m , n);
    }
};