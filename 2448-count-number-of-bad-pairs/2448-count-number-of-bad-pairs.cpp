class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long> m;
        long long n = nums.size();
        for(int i=0 ; i<nums.size() ; i++){
            m[i-nums[i]]++;
        }
        long long ans = n*(n-1)/2;
        for(auto i:m){
            ans = ans -(i.second*(i.second-1))/2;
        }
        return ans;

    }
};