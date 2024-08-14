class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        set<pair<int,int>> s;
        for(int i=0 ; i<mines.size() ; i++){
            s.insert({mines[i][0],mines[i][1]});
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=0 ; j<n ; j++){
                if(s.count({i,j}) == 0){
                    dp[i][j]=!s.count({i+1,j})+dp[i+1][j];
                }
            }
        }
        vector<vector<int>> dp2(n+1,vector<int>(n+1,0));
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<n ; j++){
                if(s.count({i,j}) == 0){
                    dp2[i][j]=dp2[i][j-1] + !s.count({i,j-1}) ;
                }
            }
        }
        vector<vector<int>> dp3(n+1,vector<int>(n+1,0));
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(s.count({i,j}) == 0){
                    dp3[i][j]=dp3[i-1][j]+ !s.count({i-1,j}) ;
                }
            }
        }
        vector<vector<int>> dp4(n+1,vector<int>(n+1,0));
        for(int i=0 ; i<n ; i++){
            for(int j=n-2 ; j>=0 ; j--){
                if(s.count({i,j}) == 0){
                    dp4[i][j]=dp4[i][j+1] + !s.count({i,j+1}) ;
                }
            }
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(s.count({i,j})==0){
                    ans = max(ans , 1+min(dp[i][j],min(dp2[i][j], min(dp3[i][j],dp4[i][j]))));
                }
            }
        }
        return ans;

        
    }
};