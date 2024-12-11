class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> dp(26,vector<int>(51,0));
        int n = s.length();
        
        // vector<int> count(50,1);
        int prev=1;
        for(int i=0 ; i<n ; i++){
            int len = 1;
            if(i>0 && s[i-1]==s[i]){
                // int index = i-1;
                // if(index!=-1){
                    len = prev+1;
                    // count[i]=count[i-1]+1;
                // }
                prev++;
            }
            else{
                prev=1;
            }
            int row = s[i]-'a';
            for(int j=1 ; j<=len ; j++){
                dp[row][j]++;
            }
        }
        int ans = -1;
        for(int i=0 ; i<26 ; i++){
            for(int j=0 ; j<51 ; j++){
                if(dp[i][j]>=3){
                    ans = max(ans , j);
                }
            }
        }
        return ans;

    }
};