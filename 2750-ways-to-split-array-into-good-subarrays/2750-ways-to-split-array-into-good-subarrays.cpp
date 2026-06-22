class Solution {
    #define mod 1000000007
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        int temp = 0;
        int i=0;
        while(i<nums.size() && nums[i] != 1){
            i++;
        }
        if(i==nums.size()){
            return 0;
        }
        // cout<<i<<endl;
        // i--;
        while(i<nums.size()){
            
            if(nums[i]==1 && temp != 0){
                // cout<<temp<<endl;
                ans = (ans%mod * temp%mod)%mod;
                temp = 1;
            }
            else{
                temp++;
            }
            i++;
        }
        return ans%mod;
    }
};