class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n =grid.size() ;
        int m = grid[0].size();
        for( int row = 0; row<n; row++){
            for(int col=0;col<m ; col++){
                if(grid[row][col]==1){
                    ans = ans + 4;

                    //check left(row , col-1)
                    if( col-1 >= 0 && grid[row][col-1]==1){
                        ans--;
                    }
                    //check right (row , col+1)
                    if(col+1 < m && grid[row][col+1]==1){
                        ans--;
                    }
                    //check up(row-1 , col)
                    if(row-1 >=0 && grid[row-1][col]==1 ){
                        ans--;
                    }
                    //check down (row+1,col)
                    if(row+1 < n && grid[row+1][col]==1){
                        ans--;
                    }
                }

            }
        }
        return ans;
    }
};