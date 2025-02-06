class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        vector<int> prefix(n,0);
        for(int i=1 ; i<n ; i++){
            if(nums[i]>temp){
                prefix[i]=1;
            }
            temp = min(nums[i],temp);
        }
        temp = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i]<temp){
                if(prefix[i]==1){
                    return true;
                }
            }
            temp = max(temp,nums[i]);
        }
        return false;
    }
};