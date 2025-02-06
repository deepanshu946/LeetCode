class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0;
        queue<pair<int,int>> q;
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        q.push({entrance[0],entrance[1]});
                vis[entrance[0]][entrance[1]]=1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size ; i++){
                pair<int,int> p = q.front();
                
                q.pop();
                if((p.first !=entrance[0] || p.second != entrance[1] )&&  (p.first == 0 || p.first == m-1 || p.second == 0 || p.second == n-1)){
                    return ans;
                }
                int row = p.first;
                int col = p.second;
                if(row+1<m && maze[row+1][col] == '.' && !vis[row+1][col]){
                    vis[row+1][col]=1;

                    q.push({row+1,col});
                }
                if(row-1>=0 && maze[row-1][col] == '.' && !vis[row-1][col]){
                vis[row-1][col]=1;

                    q.push({row-1,col});
                }
                if(col+1<n && maze[row][col+1] == '.' && !vis[row][col+1]){
                vis[row][col+1]=1;

                    q.push({row,col+1});
                }
                if(col-1>=0 && maze[row][col-1] == '.' && !vis[row][col-1]){
                vis[row][col-1]=1;

                    q.push({row,col-1});
                }
            }
            ans++;
            

        }
        return -1;
    }
};