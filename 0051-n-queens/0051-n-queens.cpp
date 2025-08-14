class Solution {
private:
bool canplace(int row , int col , vector<string> &temp , int n){
    for(int i=row+1 ; i<n ; i++){
        if(temp[i][col]=='Q'){
            return false;
        }

    }
    for(int i=row-1 ; i>=0 ; i--){
        if(temp[i][col]=='Q'){
            return false;
        }
    }
    for(int i=col+1 ; i<n ; i++){
        if(temp[row][i] == 'Q'){
            return false;
        }
    }
    for(int i=col-1 ; i>=0 ; i--){
        if(temp[row][i] == 'Q'){
            return false;
        }
    }
    for(int i=row+1, j=col+1 ; i<n && j<n ; i++,j++){
        if(temp[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1, j=col+1 ; i>=0 && j<n ; i--,j++){
        if(temp[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row+1, j=col-1 ; i<n && j>=0 ; i++,j--){
        if(temp[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1, j=col-1 ; i>=0 && j>=0 ; i--,j--){
        if(temp[i][j]=='Q'){
            return false;
        }
    }
    return true;

}
void solve(int row , int n , vector<string> &temp, vector<vector<string>> &ans){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0 ; i<n ; i++){
        if(canplace(row,i,temp,n)){
            temp[row][i]='Q';
            solve(row+1,n,temp,ans);
            temp[row][i]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,"");
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                temp[i].push_back('.');
            }
        }

        solve(0,n,temp,ans);
        return ans;
    }
};