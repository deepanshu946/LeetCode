class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        res[0][0]=grid[0][0];
        deque<pair<int,int>> pq;
        pq.push_front({0,0});
        while(!pq.empty()){
            pair<int,int> top = pq.front();
            pq.pop_front();
            int i=top.first;
            int j = top.second;
            if(i+1 < m){
                if(res[i][j] + grid[i+1][j] < res[i+1][j]){
                    res[i+1][j] = res[i][j] + grid[i+1][j];
                    if(grid[i+1][j]){
                        pq.push_back({i+1,j});
                    }
                    else{
                        pq.push_front({i+1,j});
                    }
                }
            }
            if(j+1 < n){
                if(res[i][j] + grid[i][j+1] < res[i][j+1]){
                    res[i][j+1] = res[i][j] + grid[i][j+1];
                    if(grid[i][j+1]){
                        pq.push_back({i,j+1});
                    }
                    else{
                        pq.push_front({i,j+1});
                    }
                }
            }
            if(i-1 >=0){
                if(res[i][j] + grid[i-1][j] < res[i-1][j]){
                    res[i-1][j] = res[i][j] + grid[i-1][j];
                    if(grid[i-1][j]){
                        pq.push_back({i-1,j});
                    }
                    else{
                        pq.push_front({i-1,j});
                    }
                }
            }
            if(j-1 >=0){
                if(res[i][j] + grid[i][j-1] < res[i][j-1]){
                    res[i][j-1] = res[i][j] + grid[i][j-1];
                    if(grid[i][j-1]){
                        pq.push_back({i,j-1});
                    }
                    else{
                        pq.push_front({i,j-1});
                    }
                }
            }
        }
        return health - res[m-1][n-1] >=1;
    
    }
};