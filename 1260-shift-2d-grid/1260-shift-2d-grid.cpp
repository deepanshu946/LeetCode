class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rowshift = k/grid[0].size();
        int leftshift = k%grid[0].size();
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid;
        int actualrowshift = rowshift%grid.size();
        // cout<<leftshift<<" "<<actualrowshift<<endl;
        for(int i=0 ; i<n ; i++){
            vector<int> temp;
            if(i==0){
                vector<int> prev = grid[n-1];
                for(int j=m-leftshift ; j<m ; j++){
                    temp.push_back(prev[j]);
                }
                for(int j=0 ; j<m-leftshift ; j++){
                    temp.push_back(grid[i][j]);
                }
            }
            else{
                vector<int> prev = grid[i-1];
                for(int j=m-leftshift ; j<m ; j++){
                    temp.push_back(prev[j]);
                }
                for(int j=0 ; j<m-leftshift ; j++){
                    temp.push_back(grid[i][j]);
                }
            }
            ans[(i+actualrowshift)%n]=temp;
            
        }
        return ans;
    }
};