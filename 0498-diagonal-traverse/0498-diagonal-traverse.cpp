class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        bool red = true;
        int row = 0;
        int col = 0;
        vector<int> ans;
        while(row<=m && col<=n){
            int i=row;
            int j = col;
            if(red){
                while(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    if(i-1<0 || j+1>=n){
                        break;
                    }
                    else{
                        i=i-1;
                        j=j+1;
                    }
                }
                if(j+1==n){
                    row = i+1;
                    col = j;
                }
                else{
                    col = j+1;
                    row=i;
                }
            }
            else{
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    if(i+1>=m || j-1<0){
                        break;
                    }
                    else{
                        i=i+1;
                        j=j-1;
                    }
                }
                if(i+1 ==m){
                    col = j+1 ;
                    row = i;
                }
                else{
                    row = i+1;
                    col = j;
                }
            }
            red=!red;
        }
        return ans;
    }
};