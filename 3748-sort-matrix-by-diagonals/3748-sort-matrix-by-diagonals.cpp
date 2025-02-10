class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0 ; i<m ; i++){
            int row=i;
            int col=0;
            vector<int>temp;
            while(row<m && col<n){
                temp.push_back(grid[row][col]);
                row=row+1;
                col=col+1;
            }
            sort(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());
            row=i;
            col=0;
            int j=0;
            while(row<m && col<n){
                grid[row][col]=temp[j];
                j++;
                row=row+1;
                col=col+1;
            }
        }
        for(int j=1 ; j<n ; j++){
            int col=j;
            int row=0;
            vector<int>temp;
            while(row<m && col<n){
                temp.push_back(grid[row][col]);
                row=row+1;
                col=col+1;
            }
            sort(temp.begin(),temp.end());
            col=j;
            row=0;
            int i=0;
            while(row<m && col<n){
                grid[row][col]=temp[i];
                i++;
                row=row+1;
                col=col+1;
            }
        }
        return grid;
    }
};