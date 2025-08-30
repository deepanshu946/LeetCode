class Solution {
private:
bool issafe(int row, int col, vector<vector<char>>& board, char val) {
    int cnt =0;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val) {
                cnt++;
            }
            if (board[i][col] == val) {
                cnt++;
            }
            if (board[3*(row/3)+i/3][3*(col/3)+i%3]== val) {
                cnt++;
            }
        }
        if(cnt>3){
            return false;
        }
        else{
            return true;
        }
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0 ; row<9 ; row++){
            for(int col =0; col<9 ; col++){
                if(board[row][col] != '.'){
                    char val = board[row][col];
                    if(!issafe(row,col,board,val)){
                        return false;
                    };
                }
            }
        }
        return true;
    }
};