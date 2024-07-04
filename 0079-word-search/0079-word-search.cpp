class Solution {
private:
void solve(vector<vector<char>>& board, string word,bool &ans , int i , int j , int m , int n , vector<vector<bool>> &vis,string temp){
    temp.push_back(board[i][j]);
    if(temp.length()>word.length()){
        return;
    }
    if(temp == word){
        ans = 1;
        return;
    }
    vis[i][j]=1;
    if(i+1 < m && !vis[i+1][j] ){
        solve(board,word,ans,i+1,j,m,n,vis,temp);
    }
    if(j+1 < n && !vis[i][j+1] ){
        solve(board,word,ans,i,j+1,m,n,vis,temp);
    }
    if(i-1 >=0  && !vis[i-1][j] ){
        solve(board,word,ans,i-1,j,m,n,vis,temp);
    }
    if(j-1 >=0 && !vis[i][j-1] ){
        solve(board,word,ans,i,j-1,m,n,vis,temp);
    }
    vis[i][j]=0;
    temp.pop_back();

}
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = 0;
        string temp = "";
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j]==word[0]){
                    solve(board,word,ans,i,j,m,n,vis,temp);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return 0;
    }
};