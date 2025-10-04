class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int mini = 10e6;
        long long ans = 0;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j = 0 ; j<matrix[0].size() ; j++){
                if(matrix[i][j] < 0){
                    count++;
                }
                ans = ans + abs(matrix[i][j]);
                mini = min(mini , abs(matrix[i][j]));
            }
        }
        if(count%2==0){
            return ans;
        }
        ans = ans - mini - mini;
        return ans;

    }
};