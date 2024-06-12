class Solution {
private:
bool checkdead(int row , int col , vector<vector<int>> &board){
    int m = board.size();
    int n = board[0].size();
    int neighbour = 0;
    //left,right,up,down
    if(col-1 >= 0 && board[row][col-1] == 1)
        neighbour++;
    if(col+1 < n && board[row][col+1] == 1)
        neighbour++;
    if(row-1 >= 0 && board[row-1][col] == 1)
        neighbour++;
    if(row+1 < m  && board[row+1][col] == 1)
        neighbour++;

    //diagonals
    if(col-1 >= 0 && row-1 >=0 &&  board[row-1][col-1] == 1)
        neighbour++;
    if(col-1 >= 0 && row+1 < m && board[row+1][col-1] == 1)
        neighbour++;
    if(col+1 < n && row-1 >=0 && board[row-1][col+1] == 1)
        neighbour++;
    if(col+1 < n && row+1 < m  && board[row+1][col+1] == 1)
        neighbour++;

    if(neighbour == 3){
        return true;
    }
    return false;
}
bool checklive(int row , int col , vector<vector<int>> &board){
    int m = board.size();
    int n = board[0].size();
    int neighbour = 0;
    //left,right,up,down
    if(col-1 >= 0 && board[row][col-1] == 1)
        neighbour++;
    if(col+1 < n && board[row][col+1] == 1)
        neighbour++;
    if(row-1 >= 0 && board[row-1][col] == 1)
        neighbour++;
    if(row+1 < m  && board[row+1][col] == 1)
        neighbour++;

    //diagonals
    if(col-1 >= 0 && row-1 >=0 &&  board[row-1][col-1] == 1)
        neighbour++;
    if(col-1 >= 0 && row+1 < m && board[row+1][col-1] == 1)
        neighbour++;
    if(col+1 < n && row-1 >=0 && board[row-1][col+1] == 1)
        neighbour++;
    if(col+1 < n && row+1 < m  && board[row+1][col+1] == 1)
        neighbour++;
    
    if(neighbour<2 || neighbour > 3){
        return true;
    }
    return false;

}
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> change(m,vector<bool>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ;j++){
                if(board[i][j]==0){
                    if(checkdead(i,j,board)){
                        change[i][j]=1;
                    }
                }
                else{
                    if(checklive(i,j,board)){
                        change[i][j]=1;
                    }
                }
            }
        }
        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(change[i][j]){
                    if(board[i][j]==1){
                        board[i][j]=0;
                    }
                    else{
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};