class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0 ; i<n ; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int j=0 ; j<m ; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        while(!q.empty()){
            pair<int,int> temp = q.front();
            int i=temp.first;
            int j = temp.second;
            q.pop();
            if(i+1<n && !vis[i+1][j] && board[i+1][j]=='O'){
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j+1<m && !vis[i][j+1] && board[i][j+1]=='O'){
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
            if(i-1>=0 && !vis[i-1][j] && board[i-1][j]=='O'){
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            if(j-1>=0 && !vis[i][j-1] && board[i][j-1]=='O'){
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
        }
        for(int i=1 ; i<n-1 ; i++){
            for(int j=1 ; j<m-1 ; j++){
                if(board[i][j]=='O' && vis[i][j]==0 ){
                    board[i][j]='X';
                }
            }
        }
        
    }
};