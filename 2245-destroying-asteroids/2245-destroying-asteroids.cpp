class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long val = mass;
        for(int i=0 ; i<nums.size() ; i++){
            
            if(val<nums[i]){
                return 0;
            }
            val = val + nums[i];
            
        }
        return 1;
    }
};