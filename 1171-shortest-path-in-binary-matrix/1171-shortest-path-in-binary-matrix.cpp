// class comp{
//     bool operator()(pair<int,pair<int,int>> p1 , pair<int,pair<int,int>> p2){
//         if(p1.first != p2.first){
//             return p1.first>p2.first;
//         }
//         return p1.second.first>p2.second.first;
//     }
// };
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n , vector<int>(m,INT_MAX));
        dist[0][0]=0;
        if(grid[0][0]==1){
            return -1;
        }
        q.push({0,{0,0}});
        while(!q.empty()){
            pair<int,pair<int,int>> temp = q.front();
            q.pop();
            int row = temp.second.first;
            int col = temp.second.second;
            int d = temp.first;
            if(row+1<n && d+1 < dist[row+1][col] && grid[row+1][col]==0){
                dist[row+1][col]=d+1;
                q.push({d+1,{row+1,col}});
            }
            if(col+1<m && d+1 < dist[row][col+1]  && grid[row][col+1]==0){
                dist[row][col+1]=d+1;
                q.push({d+1,{row,col+1}});
            }
            if(row-1>=0 && d+1 < dist[row-1][col]  && grid[row-1][col]==0){
                dist[row-1][col]=d+1;
                q.push({d+1,{row-1,col}});
            }
            if(col-1>=0 && d+1 < dist[row][col-1]  && grid[row][col-1]==0){
                dist[row][col-1]=d+1;
                q.push({d+1,{row,col-1}});
            }
            if(row+1<n && col+1<m && d+1 < dist[row+1][col+1]  && grid[row+1][col+1]==0){
                dist[row+1][col+1]=d+1;
                q.push({d+1,{row+1,col+1}});
            }
            if(row+1<n && col-1>=0 && d+1 < dist[row+1][col-1]  && grid[row+1][col-1]==0){
                dist[row+1][col-1]=d+1;
                q.push({d+1,{row+1,col-1}});
            }
            if(row-1>=0 && col-1>=0 && d+1 < dist[row-1][col-1]  && grid[row-1][col-1]==0){
                dist[row-1][col-1]=d+1;
                q.push({d+1,{row-1,col-1}});
            }
            if(row-1>=0 && col+1<m && d+1 < dist[row-1][col+1]  && grid[row-1][col+1]==0){
                dist[row-1][col+1]=d+1;
                q.push({d+1,{row-1,col+1}});
            }

        }
        if(dist[n-1][m-1] == INT_MAX){
            return -1;
        }
        return dist[n-1][m-1]+1;
    }
};