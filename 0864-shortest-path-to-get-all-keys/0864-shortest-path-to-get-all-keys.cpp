class Solution {

public:
    struct state{
        int row ;
        int col ;
        int mask;
    };
    int shortestPathAllKeys(vector<string>& grid) {
        //state -> row , col, {keys} 
        //stop when keycount is reached
        int m = grid.size();
        int n = grid[0].size();
        int x;
        int y;
        int locks = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]=='@'){
                    x = i;
                    y=j;

                }
                if(grid[i][j]>='a' && grid[i][j]<='z'){
                    locks++;
                }
            }
        }
        int maxmask = (1<<locks)-1;
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(maxmask+1,0)));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<state> pq;
        pq.push({x,y,0});
        vis[x][y][0]=1;
        int moves = 0;
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                state t = pq.front();
                pq.pop();
                if(t.mask == maxmask){
                    return moves;
                }
                int i = t.row;
                int j = t.col;
                int currmask = t.mask;
                for(auto &d : dir){
                    int nextrow = i + d[0];
                    int nextcol = j + d[1];
                    int newmask = currmask;
                    if(nextrow >=m || nextcol>=n || nextrow <0 || nextcol<0){
                        continue;
                    }
                    if(grid[nextrow][nextcol]=='#'){
                        continue;
                    }
                    if(grid[nextrow][nextcol] >='a' && grid[nextrow][nextcol]<='z'){
                        int bit = grid[nextrow][nextcol] - 'a';
                        newmask = newmask | (1<<bit);
                    }
                    if(grid[nextrow][nextcol] >='A' && grid[nextrow][nextcol]<='Z'){
                        int bit = grid[nextrow][nextcol] - 'A';
                        if((newmask & (1<<bit))==0){
                            continue;
                        }
                    }
                    if(!vis[nextrow][nextcol][newmask]){
                        pq.push({nextrow,nextcol,newmask});
                        vis[nextrow][nextcol][newmask]=1;
                    }
                }
            }
            moves++;
        }
        return -1;
        


    }
};