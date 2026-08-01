class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rowstart = 0;
        int rowend = n-1;
        int colstart = 0;
        int colend = n-1;
        int var = 1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(rowstart<=rowend && colstart<=colend){
            for(int j = colstart ; j<=colend ; j++){
                ans[rowstart][j]=var;
                var++;
            }
            rowstart++;
            if(rowstart>rowend && colstart>colend)break;
            for(int i=rowstart ; i<=rowend ; i++){
                ans[i][colend]=var;
                var++;
            }
            colend--;
            if(rowstart>rowend && colstart>colend)break;
            for(int j=colend ; j>=colstart ; j--){
                ans[rowend][j]=var;
                var++;
            }
            rowend--;
            if(rowstart>rowend && colstart>colend)break;

            for(int i=rowend ; i>=rowstart ; i--){
                ans[i][colstart]=var;
                var++;
            }
            colstart++;
            if(rowstart>rowend && colstart>colend)break;
        }
        return ans;
    }
};