class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
           for(int j=0 ; j<m ; j++){
            if(grid[i][j]==2){
                q.push(make_pair(i,j));
            }
           }
        }
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            bool check = 0;
            for(int k=0 ; k<size ; k++){
                pair<int,int> p = q.front();
                q.pop();
                int i=p.first;
                int j = p.second;
                //left
                if(j-1 >= 0 && grid[i][j-1]==1){
                    q.push(make_pair(i,j-1));
                    grid[i][j-1]=2;
                    check=1;
                }
                //right
                if(j+1 < m && grid[i][j+1]==1){
                    q.push(make_pair(i,j+1));
                    grid[i][j+1]=2;

                    check=1;
                }
                //top
                if(i-1 >= 0 && grid[i-1][j]==1){
                    q.push(make_pair(i-1,j));
                    grid[i-1][j]=2;

                    check=1;
                }
                //down
                if(i+1 <n && grid[i+1][j]==1){
                    q.push(make_pair(i+1,j));
                    grid[i+1][j]=2;

                    check=1;
                }

            }
            if(check==1){
                ans++;
            }
        }
        for(int i=0 ; i<n ; i++){
           for(int j=0 ; j<m ; j++){
            if(grid[i][j]==1){
                ans = -1;
                return ans;
            }
           }
        }
        return ans;
    }
};