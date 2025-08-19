class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
          int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n , vector<int>(m,INT_MAX));
        dist[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            pair<int,pair<int,int>> temp = q.front();
            q.pop();
            int row = temp.second.first;
            int col = temp.second.second;
            int d = temp.first;
            // if(row==n-1 && col==m-1){
            //     return d;
            // }
            if(row+1<n && max(d,abs(grid[row+1][col] - grid[row][col])) < dist[row+1][col]){
                dist[row+1][col]= max(d,abs(grid[row+1][col] - grid[row][col]));
                q.push({max(d,abs(grid[row+1][col] - grid[row][col])) ,{row+1,col}});
            }
            if(col+1<m && max(d,abs(grid[row][col+1] - grid[row][col])) < dist[row][col+1] ){
                dist[row][col+1]= max(d,abs(grid[row][col+1] - grid[row][col])) ;
                q.push({max(d,abs(grid[row][col+1] - grid[row][col])),{row,col+1}});
            }
            if(row-1>=0 && max(d,abs(grid[row-1][col] - grid[row][col])) < dist[row-1][col]){
                dist[row-1][col]= max(d,abs(grid[row-1][col] - grid[row][col]));
                q.push({max(d,abs(grid[row-1][col] - grid[row][col])),{row-1,col}});
            }
            if(col-1>=0 && max(d,abs(grid[row][col-1] - grid[row][col])) < dist[row][col-1]){
                dist[row][col-1]=max(d,abs(grid[row][col-1] - grid[row][col]));
                q.push({max(d,abs(grid[row][col-1] - grid[row][col])),{row,col-1}});
            }

        }
        // if(dist[n-1][m-1] == INT_MAX){
        //     return -1;
        // }
        return dist[n-1][m-1];
    
    }
};