class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = 0;
        int col = 0;
        int n = matrix.size();
        while(row<n){
            int i=row;
            int j=col;
            while(i<n){
                swap(matrix[row][j],matrix[i][col]);
                i++;
                j++;
            }
            row++;
            col++;
        }
        for(int i=0 ; i<n ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    
    }
};