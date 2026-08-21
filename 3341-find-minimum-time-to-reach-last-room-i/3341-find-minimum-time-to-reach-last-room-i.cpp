class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        ans[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            pair<int,pair<int,int>> t = pq.top();
            pq.pop();
            int curr = t.first;
            int i= t.second.first;
            int j= t.second.second;
            if(i+1<n){
                int wait = grid[i+1][j] - curr;
                int finaltime = 0;
                if(wait < 0){
                    finaltime = curr+1;
                }
                else{
                    finaltime = curr + wait + 1;
                }
                if(finaltime < ans[i+1][j]){
                    ans[i+1][j] = finaltime;
                    pq.push({finaltime ,{ i+1, j}});
                }
            }
            if(j+1<m){
                int wait = grid[i][j+1] - curr;
                int finaltime = 0;
                if(wait < 0){
                    finaltime = curr+1;
                }
                else{
                    finaltime = curr + wait + 1;
                }
                if(finaltime < ans[i][j+1]){
                    ans[i][j+1] = finaltime;
                    pq.push({finaltime , {i, j+1}});
                }
            }
            if(i-1 >= 0){
                int wait = grid[i-1][j] - curr;
                int finaltime = 0;
                if(wait < 0){
                    finaltime = curr+1;
                }
                else{
                    finaltime = curr + wait + 1;
                }
                if(finaltime < ans[i-1][j]){
                    ans[i-1][j] = finaltime;
                    pq.push({finaltime , {i-1, j}});
                }
            }
            if(j-1>=0){
                int wait = grid[i][j-1] - curr;
                int finaltime = 0;
                if(wait < 0){
                    finaltime = curr+1;
                }
                else{
                    finaltime = curr + wait + 1;
                }
                if(finaltime < ans[i][j-1]){
                    ans[i][j-1] = finaltime;
                    pq.push({finaltime , {i, j-1}});
                }
            }

        }
        return ans[n-1][m-1];
    }
};