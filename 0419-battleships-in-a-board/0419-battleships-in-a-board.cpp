class Solution {
private:
bool check(int i , int j ,vector<vector<char>>& board){
    if(i>0 && board[i-1][j]=='X'){
        return false;
    }
    if(i+1<board.size() && board[i+1][j]=='X'){
        return false;
    }
    return true;
}
bool check2(int i , int j ,vector<vector<char>>& board){
    if(j>0 && board[i][j-1]=='X'){
        return false;
    }
    if(j+1<board[0].size() && board[i][j+1]=='X'){
        return false;
    }
    return true;
}
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i=0 ; i<board.size() ; i++){
            int curr=-1;
            for(int j=0 ; j<board[0].size() ; j++){

                if(board[i][j]=='X' && check(i,j,board)){
                    if(curr==-1){
                        curr=1;
                    }
                    else{
                        curr++;
                    }
                }
                else{
                    if(curr>0){
                        ans++;
                    }
                    curr=0;
                }
            }
            if(curr>0){
                ans++;
            }
        }
        for(int j=0 ; j<board[0].size() ; j++){
            int curr = 0;
            for(int i=0 ; i<board.size() ; i++){
                if(board[i][j]=='X' && check2(i,j,board)){
                    if(curr==-1){
                        curr=1;
                    }
                    else{
                        curr++;
                    }
                }
                else{
                    if(curr>1){
                        ans++;
                    }
                    curr=0;
                }
            }
            if(curr>1){
                ans++;
            }
        }
        return ans;
    }
};