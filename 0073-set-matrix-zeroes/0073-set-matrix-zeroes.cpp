class Solution {
private:
void solve(pair<int,int> p , vector<vector<int>> &matrix){
    int row = p.first;
    int col = p.second;
    for(int i=0 ; i<matrix[0].size() ; i++){
        matrix[row][i]=0;
    }
    for(int i=0 ; i<matrix.size() ; i++){
        matrix[i][col]=0;
    }
}
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zero;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j]==0){
                    pair<int,int> p = make_pair(i,j);
                    zero.push_back(p);
                }
            }
        }
        for(int i=0 ; i<zero.size() ; i++){
            solve(zero[i],matrix);
        }
        
    }
};