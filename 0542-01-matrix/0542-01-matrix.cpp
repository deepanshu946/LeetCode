class Solution {
private:
int solve(vector<vector<int>> &mat,vector<vector<bool>> &visited,int i, int j , int m , int n,vector<vector<int>> &dp){
    if(mat[i][j]==0){
        return dp[i][j]=0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    visited[i][j]=1;
    int ans = 1e9;
    if(j+1<n && !visited[i][j+1])
         ans = min(ans,1+solve(mat,visited,i,j+1,m,n,dp)) ;
    if(i+1 < m && !visited[i+1][j])
         ans  = min(ans,1+solve(mat,visited,i+1,j,m,n,dp));
    if(j-1>=0 &&!visited[i][j-1])
         ans  = min(ans,1+solve(mat,visited,i,j-1,m,n,dp));
    if(i-1>=0 && !visited[i-1][j])
         ans  = min(ans,1+solve(mat,visited,i-1,j,m,n,dp));
    visited[i][j]=0;
    // if(ans == 1e9){
    //     return  dp[i][j]=2;
    // }
    return dp[i][j]=ans;
}
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=0 ; j<mat[0].size() ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i+1<m && ans[i+1][j]==0 && mat[i+1][j]==1){
                ans[i+1][j]=ans[i][j]+1;
                q.push({i+1,j});
            }
             if(i-1>=0 && ans[i-1][j]==0&&mat[i-1][j]==1 ){
                ans[i-1][j]=ans[i][j]+1;
                q.push({i-1,j});
            }
             if(j+1<n && ans[i][j+1]==0 &&mat[i][j+1]==1){
                ans[i][j+1]=ans[i][j]+1;
                q.push({i,j+1});
            }
            if(j-1>=0 && ans[i][j-1]==0 &&mat[i][j-1]==1){
                ans[i][j-1]=ans[i][j]+1;
                q.push({i,j-1});
            }
        }
        return ans;



    }
};