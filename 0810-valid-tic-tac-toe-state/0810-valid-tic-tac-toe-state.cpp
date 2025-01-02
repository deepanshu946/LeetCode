class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int zero = 0;
        int one = 0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(board[i][j]=='O'){
                    zero++;
                }
                if(board[i][j]=='X'){
                    one++;
                }
            }
        }
        if(zero > one){
            return false;
        }

        if(zero != one && zero+1 != one){
            return false;
        }
        int zerocount=0;
        int onecount=0;
        for(int i=0 ; i<3 ; i++){
            if(board[i]=="XXX"){
                onecount++;
            }
            if(board[i]=="OOO"){
                zerocount++;
            }
        }
        for(int j=0 ; j<3 ; j++){
            string temp = "";
            for(int i=0 ; i<3 ; i++){
                temp = temp + board[i][j];
            }
            if(temp=="XXX"){
                onecount++;
            }
            if(temp=="OOO"){
                zerocount++;
            }
        }
        string temp;
        temp.push_back(board[0][0]);
        temp.push_back(board[1][1]);
        temp.push_back(board[2][2]);

        if(temp=="XXX"){
            onecount++;
        }
        if(temp=="OOO"){
            zerocount++;
        }
        temp="";
        temp.push_back(board[0][2]);
        temp.push_back(board[1][1]);
        temp.push_back(board[2][0]);
        if(temp=="XXX"){
            onecount++;
        }
        if(temp=="OOO"){
            zerocount++;
        }
        if(zerocount != 0 && onecount!= 0){
            return false;
        }
        if(zerocount>2 || onecount>2){
            return false;
        }
        if(onecount!= 0 && zero==one){
            return false;
        }
        if(zerocount!=0 && zero<one){
            return false;
        }
        return true;


        

    }
};