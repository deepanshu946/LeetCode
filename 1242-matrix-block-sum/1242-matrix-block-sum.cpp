class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=1 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                mat[i][j]=mat[i][j]+mat[i-1][j];
            }
        }
        for(int j=1 ; j<n ; j++){
            for(int i=0 ; i<m ; i++){
                mat[i][j]=mat[i][j]+mat[i][j-1];
            }
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int x1 = i-k;
                int x2 = i+k;
                int y1 = j-k;
                int y2 = j+k;
                //normalize
                if(x1<0){
                    x1=0;
                }
                if(y1<0){
                    y1=0;
                }
                if(x2>=m){
                    x2=m-1;
                }
                if(y2>=n){
                    y2=n-1;
                }
                ans[i][j]=mat[x2][y2];
                if(x1>0){
                    ans[i][j] -= mat[x1-1][y2];
                }
                if(y1>0){
                    ans[i][j] -= mat[x2][y1-1];
                }
                if(x1>0 && y1>0){
                    ans[i][j] += mat[x1-1][y1-1];
                }
            }

        }
        return ans;
    }
};