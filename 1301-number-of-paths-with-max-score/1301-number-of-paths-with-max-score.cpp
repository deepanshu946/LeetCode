class Solution {
private:
#define mod 1000000007 
// pair<int,int> solve(int i , int j , int m , int n , vector<vector<int>> &board){
//     if(i==m-1 && j==n-1){
//         return {0,1};
//     }
//     pair<int,int> right = {INT_MIN,0};
//     pair<int,int> down = {INT_MIN,0};
//     pair<int,int> dia = {INT_MIN,0};

//     if(j+1 < n && board[i][j+1] != -1){
//         right = solve(i,j+1,m,n,board);
//     }
//     if(i+1 < m && board[i+1][j] != -1){
//         down = solve(i+1,j,m,n,board);
//     }
//     if(i+1<m && j+1<n && board[i+1][j+1] != -1){
//         dia = solve(i+1,j+1,m,n,board);
//     }
//     int maxval = max(right.first,max(down.first,dia.first));
//     int paths = 0;
//     if(maxval==right.first){
//         paths=paths+right.second;
//     }
//     if(maxval==down.first){
//         paths=paths+down.second;
//     }
//     if(maxval==dia.first){
//         paths=paths+dia.second;
//     }
//     return {maxval+board[i][j],paths};


// }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].length();
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == 'E'){
                    grid[i][j]=0;
                }
                else if(board[i][j]=='X'){
                    grid[i][j]=-1;
                }
                else{
                    grid[i][j]=board[i][j]-'0';
                }
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    vector<vector<pair<int,int>>> dp(m+1 , vector<pair<int,int>>(n+1,{INT_MIN,0}));
    dp[m-1][n-1]={0,1};
    for(int i=m-1 ; i>=0 ; i--){
        for(int j=n-1 ; j>=0 ; j--){
            if((i==m-1 && j==n-1) || grid[i][j]==-1 ){
                continue;
            }
            else{
                pair<int,int> right = {INT_MIN,0};
                pair<int,int> down = {INT_MIN,0};
                pair<int,int> dia = {INT_MIN,0};

                if(j+1 < n && grid[i][j+1] != -1){
                    right = dp[i][j+1] ;
                }
                if(i+1 < m && grid[i+1][j] != -1){
                    down = dp[i+1][j] ;
                }
                if(i+1<m && j+1<n && grid[i+1][j+1] != -1){
                    dia = dp[i+1][j+1] ;
                }
                int maxval = max(right.first,max(down.first,dia.first));
                int paths = 0;
                if(maxval==right.first){
                    paths=(paths+right.second)%mod;
                }
                if(maxval==down.first){
                    paths=(paths+down.second)%mod;
                }
                if(maxval==dia.first){
                    paths=(paths+dia.second)%mod;
                }
                dp[i][j]={(maxval+grid[i][j])%mod,paths};
            }
        }
    }
        if(dp[0][0].first<0){
            dp[0][0].first=0;
        }
        return {dp[0][0].first,dp[0][0].second};


        // pair<int,int> p= solve(0,0,m,grid[0].size(),grid);
        
    }
};