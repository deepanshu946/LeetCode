class Solution {
private:
// int solve(vector<int> &nums1 , vector<int>&nums2 , int i , int j , int n , int m){
//     if(i>=n || j>=m){
//         return 0;
//     }

//     if(nums1[i]==nums2[j]){
//         return 1+solve(nums1,nums2,i+1,j+1,n,m);
//     }
//     else{
//         return 0;
//     }
// }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j] = max(dp[i][j] , 1+dp[i+1][j+1]);
                }
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans , dp[i][j]);
            }
        }
        return ans;
    }
};