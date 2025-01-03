class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> leftsum(n,0);
        vector<long long> rightsum(n,0);
        leftsum[0]=nums[0];
        for(int i=1 ; i<n ; i++){
            leftsum[i]=nums[i]+leftsum[i-1];
        }
        rightsum[n-1]=0;
        for(int i=n-2 ; i>=0 ; i--){
            rightsum[i]=nums[i+1]+rightsum[i+1];
        }
        int ans = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(leftsum[i] >= rightsum[i]){
                ans++;
            }
        }
        return ans;
    }
};