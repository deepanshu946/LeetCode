#define mod 1000000007
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0 ; i<queries.size() ; i++){
            int idx = queries[i][0];
            while(idx <= queries[i][1]){
                long long temp = nums[idx];
                nums[idx] = (temp*queries[i][3])%mod;
                idx += queries[i][2];
            }
        }
        int xorr = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            xorr = nums[i]^xorr;
        }
        return xorr;
    }
};