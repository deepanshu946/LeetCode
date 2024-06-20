class Solution {
private:
int solve(vector<int> nums1 , vector<int> nums2){
    int n = nums1.size();
    vector<vector<int>> dp(n+1 , vector<int>(2,INT_MAX));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1 ; i>=1 ; i--){
        for(int swapped=0 ; swapped<=1 ; swapped++){
            int ans = INT_MAX;
            int prev1= nums1[i-1];
            int prev2 = nums2[i-1];
            if(swapped){
                swap(prev1,prev2);
            }
            //no swap
            if(nums1[i]>prev1 && nums2[i]>prev2){
                ans = dp[i+1][0];
            }
            //swap
            if(nums1[i]>prev2 && nums2[i]>prev1){
                ans = min(ans,1+dp[i+1][1]);
            }
            dp[i][swapped]=ans;
        }
    }
    return dp[1][0];
        
    
}

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        return solve(nums1,nums2);

    }
};