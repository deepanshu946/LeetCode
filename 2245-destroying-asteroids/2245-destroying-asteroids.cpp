class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long val = mass;
        for(int i=0 ; i<nums.size() ; i++){
            int temp = 0;
            long long sum = 0;
            while(i<nums.size() && val>=nums[i]){
                sum=sum + nums[i];
                temp++;
                i++;
            }
            if(temp==0){
                return false;
            }
            i--;
            val = val + sum;
            
        }
        return 1;
    }
};