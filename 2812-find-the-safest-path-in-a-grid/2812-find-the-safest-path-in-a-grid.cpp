class Solution {
private:
int solve(int i , int j , int n , int m , vector<vector<int>> &mindist , vector<vector<bool>> &vis2){
    if(i>=n || j>=m || i<0 || j<0){
        return INT_MIN;
    }
    if(i==n-1 && j==m-1){
        return mindist[i][j];
    }
    int ans = 0;
    vis2[i][j]=1;
    if(i+1<n && !vis2[i+1][j]){
        ans = max(ans , solve(i+1,j,m,n,mindist,vis2));
    }
    if(j+1<m && !vis2[i][j+1]){
        ans = max(ans , solve(i,j+1,m,n,mindist,vis2));
    }
    if(i-1>=0 && !vis2[i-1][j]){
        ans = max(ans , solve(i-1,j,m,n,mindist,vis2));
    }
    if(j-1 >=0 && !vis2[i][j-1]){
        ans = max(ans , solve(i,j-1,m,n,mindist,vis2));
    }
    vis2[i][j]=0;
    return min(mindist[i][j],ans);
}
bool check(int i , int j , int val , int n , int m , vector<vector<int>> &mindist){
    if(mindist[0][0]<val){
        return false;
    }
    vector<vector<bool>> vis2(n,vector<bool>(m,0));
    queue<pair<int,int>> q;
    q.push({0,0});
    vis2[0][0]=1;
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(top.first == n-1 && top.second == m-1){
            return true;
        }
        if(top.first + 1 <n && !vis2[top.first+1][top.second] && mindist[top.first+1][top.second]>=val){
            q.push({top.first+1,top.second});
            vis2[top.first+1][top.second]=1;
        }
        if(top.second + 1 <m && !vis2[top.first][top.second+1] && mindist[top.first][top.second+1]>=val){
            q.push({top.first,top.second+1});
            vis2[top.first][top.second+1]=1;
        }
        if(top.first - 1 >=0 && !vis2[top.first-1][top.second] && mindist[top.first-1][top.second]>=val){
            q.push({top.first-1,top.second});
            vis2[top.first-1][top.second]=1;
        }
        if(top.second -1 >=0 && !vis2[top.first][top.second-1] && mindist[top.first][top.second-1]>=val){
            q.push({top.first,top.second-1});
            vis2[top.first][top.second-1]=1;
        }
    }
    return false;
}

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mindist(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;

                }

            }
        }
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                pair<int,int> top = q.front();

                q.pop();
                mindist[top.first][top.second]=level;
                if(top.first + 1 <n && !vis[top.first+1][top.second]){
                    q.push({top.first+1,top.second});
                    vis[top.first+1][top.second]=1;
                }
                if(top.second + 1 <m && !vis[top.first][top.second+1]){
                    q.push({top.first,top.second+1});
                    vis[top.first][top.second+1]=1;
                }
                if(top.first - 1 >=0 && !vis[top.first-1][top.second]){
                    q.push({top.first-1,top.second});
                    vis[top.first-1][top.second]=1;
                }
                if(top.second -1 >=0 && !vis[top.first][top.second-1]){
                    q.push({top.first,top.second-1});
                    vis[top.first][top.second-1]=1;
                }
            }
            level++;
        }
        vector<vector<bool>> vis2(n,vector<bool>(m,0));
        int start = 0;
        int store = 0;
        int end = level;
        while(start<=end){
            int mid = (start+end)/2;
            if(check(0,0,mid,n,m,mindist)){
                store = mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return store;
    }
};