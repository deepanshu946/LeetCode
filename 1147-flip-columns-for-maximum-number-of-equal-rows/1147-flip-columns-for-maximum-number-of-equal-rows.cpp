class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        unordered_map<string,int> m1;
        for(int i=0 ; i<n ; i++){
            string temp1="";
            string temp2="";
            for(int j=0 ; j<m  ; j++){
                if(matrix[i][j]==1){
                    temp1.push_back('1');
                    temp2.push_back('0');
                }
                else{
                    temp2.push_back('1');
                    temp1.push_back('0');
                }
            }
            m1[temp1]++;
            m1[temp2]++;
            ans=max(ans,max(m1[temp1],m1[temp2]));
        }
        return ans;
    }
};