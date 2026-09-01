class Solution {
private:
int constenergy = 0;
// int solve(int x , int y ,vector<string>& classroom , int litter , int energy , int m , int n , vector<vector<bool>> &vis ){
//     if(x >= m || y>= n || x<0 || y<0){
//         return 1e9;
//     }
//     if(classroom[x][y]=='X'){
//         return 1e9;
//     }
//     if(energy < 0){
//         return 1e9;
//     }
//     // if(litter == 0){
//     //     return 0;
//     // }
//     int ch = classroom[x][y];
//     vis[x][y]=1;

//     int ans = 1e9;
//     if(x+1 < m && !vis[x+1][y]){
//         if(ch == 'L'){
//             ans = min(ans , 1+ solve(x+1,y , classroom , litter-1,energy-1, m,n,vis));
//         }
//         else if(ch=='R'){
//             ans = min(ans , 1+ solve(x+1,y , classroom , litter-1,constenergy, m,n,vis));
//         }
//         else if(ch=='.'){
//             ans = min(ans , 1+ solve(x+1,y , classroom , litter,energy-1, m,n,vis));
//         }
//     }
//     if(y+1 < n && !vis[x][y+1]){
//         if(ch == 'L'){
//             ans = min(ans , 1+ solve(x,y+1 , classroom , litter-1,energy-1, m,n,vis));
//         }
//         else if(ch=='R'){
//             ans = min(ans , 1+ solve(x,y+1 , classroom , litter-1,constenergy, m,n,vis));
//         }
//         else if(ch=='.'){
//             ans = min(ans , 1+ solve(x,y+1 , classroom , litter,energy-1, m,n,vis));
//         }
//     }
//     if(x-1>=0 && !vis[x-1][y]){
//         if(ch == 'L'){
//             ans = min(ans , 1+ solve(x-1,y , classroom , litter-1,energy-1, m,n,vis));
//         }
//         else if(ch=='R'){
//             ans = min(ans , 1+ solve(x-1,y , classroom , litter-1,constenergy, m,n,vis));
//         }
//         else if(ch=='.'){
//             ans = min(ans , 1+ solve(x-1,y , classroom , litter,energy-1, m,n,vis));
//         }
//     }
//     if(y-1>=0 && !vis[x][y-1]){
//         if(ch == 'L'){
//             ans = min(ans , 1+ solve(x,y-1 , classroom , litter-1,energy-1, m,n,vis));
//         }
//         else if(ch=='R'){
//             ans = min(ans , 1+ solve(x,y -1, classroom , litter-1,constenergy, m,n,vis));
//         }
//         else if(ch=='.'){
//             ans = min(ans , 1+ solve(x,y-1 , classroom , litter,energy-1, m,n,vis));
//         }
//     }
//     if(ch=='R'){
//         vis[x][y]=0;
//     }
//     return ans;


// }
struct state{
    int row;
    int col ; 
    int e;
    int mask;
};

public:
    int minMoves(vector<string>& classroom, int energy) {
        int x = 0;
        int y = 0;
        constenergy = energy;
        int litter = 0;
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<int>> litterpos(m,vector<int>(n,-1));
        int currpos = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(classroom[i][j]=='S'){
                    x= i;
                    y= j;
                }
                if(classroom[i][j]=='L'){
                    litterpos[i][j]=currpos;
                    currpos++;
                }
            }
        }   
        int allcollected = (1<<currpos)-1;

        vector<vector<vector<vector<bool>>>> vis(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(constenergy+1,vector<bool>(allcollected+1,0))));
        if(currpos==0){
            return 0;
        }
        queue<state> pq;
        pq.push({x,y,constenergy,0});
        vis[x][y][constenergy][0]=1;
        int moves = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty()){
            int size = pq.size();
            for(int x=0 ; x<size ; x++){
                state t = pq.front();
                pq.pop();
                if(t.mask == allcollected){
                    return moves;
                }
                if(t.e==0){
                    continue;
                }
                int i = t.row;
                int j = t.col;
                for(auto &d : dir){
                    int nextrow = i+d[0];
                    int nextcol = j+d[1];
                    if(nextrow >= m || nextcol>=n || nextrow <0 || nextcol<0){
                        continue;
                    }
                    if(classroom[nextrow][nextcol] == 'X'){
                        continue;
                    }
                    int newenergy = t.e-1;
                    int newmask = t.mask;
                    if(litterpos[nextrow][nextcol] != -1){
                        int bit = litterpos[nextrow][nextcol];
                        newmask |= (1<<bit);
                    }
                    if(classroom[nextrow][nextcol] == 'R'){
                        newenergy = constenergy;
                    }
                    if(!vis[nextrow][nextcol][newenergy][newmask]){
                        pq.push({nextrow,nextcol,newenergy,newmask});
                        vis[nextrow][nextcol][newenergy][newmask]=1;
                    }


                }
                
            }
            moves++;
        }
        return -1;


        // vector<vector<bool>> vis(m,vector<bool>(n,0));
        // return solve(x,y,classroom,litter,energy,m,n,vis);
    }
};