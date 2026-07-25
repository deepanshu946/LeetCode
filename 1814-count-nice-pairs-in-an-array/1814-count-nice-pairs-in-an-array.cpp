#define mod 1000000007
class Solution {
private:
int getrev(int val){
    int ans = 0;
    while(val != 0){
        int rem = val%10;
        ans = ans*10 + rem;
        val = val/10;
    }
    return ans;
}
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            
            int reverse = getrev(nums[i]);
            // cout<<reverse();
            m[nums[i]-reverse]++;
        }
        int ans = 0;
        for(auto i:m){
            ans = (ans + ((1LL*i.second * (i.second-1))/2)%mod)%mod;
        }
        return ans;
    }
};