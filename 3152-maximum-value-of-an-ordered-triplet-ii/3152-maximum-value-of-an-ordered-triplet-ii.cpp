class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> left(nums.size(),0);
        vector<long long> right(nums.size(),0);
        long long maxx=0;
        for(int i=0 ; i<nums.size() ; i++){
            left[i]=maxx;
            if(nums[i]>maxx){
                maxx=nums[i];
            }
        }
        maxx=0;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            right[i]=maxx;
            if(nums[i]>maxx){
                maxx=nums[i];
            }
        }
        // return 0;
        long long ans = 0;
        for(int i=0 ; i< nums.size() ; i++){
            if(left[i]-nums[i] >0){
                if((left[i]-nums[i])*right[i] > ans){
                ans = (left[i]-nums[i])*right[i];
            }
            }
        }
        return ans;
    }
};