class Solution {
public:
    #define mod 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0 ; i<n ; i++){
            int ans = 0;
            for(int j=i ; j<n ; j++){
                ans = ans + nums[j];
                sum.push_back(ans);
            }
        }
        sort(sum.begin(),sum.end());
        int temp = 0;
        for(int i=left-1 ; i<right ; i++ ){
            temp = (temp + sum[i])%mod;
        }
        return temp;
    }
};