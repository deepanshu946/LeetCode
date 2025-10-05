class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> count(n,vector<int>(m+1,0));
        for(int i=0 ; i<n ; i++){
            int pre = 0;
            for(int j=0 ; j<m ; j++){
                if(nums[i][j]=='#'){
                    pre++;
                }
                if(nums[i][j]=='*'){
                    count[i][j]=pre;
                    pre=0;
                }
            }
            if(pre != 0){
                count[i][m]=pre;
            }

        }
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        vector<vector<char>> temp(n,vector<char>(m,'.'));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(nums[i][j]=='*'){
                    temp[i][j]='*';
                    int val = count[i][j];
                    int tj = j-1;
                    while(val--){
                        temp[i][tj]='#';
                        tj--;
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            if(count[i][m] != 0){
                int ty = m-1;
                int val = count[i][m];
                while(val--){
                    temp[i][ty]='#';
                    ty--;
                }
            }
        }
        int ansstartcol = n-1;
        int ansstartrow = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans[ansstartrow][ansstartcol]=temp[i][j];
                ansstartrow++;
            }
            ansstartrow=0;
            ansstartcol--;
        }

        
        return ans;
    }
};