class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        if(nums.size()==1){
            if(k%2==0){
                return nums[0];
            }
            return -1;
        }
        // if(k==nums.size()){
        //     int a = 0;
        //     for(int i=0 ; i<)
        // }
        if(k>nums.size()){
            // if(k%nums.size()==0){
            //     return -1;
            // }
            // return -1;
            int temp = 0;
            for(int i=0;i<nums.size(); i++){
                temp=max(temp,nums[i]);
            }
            return temp;

        }
        for(int i=0 ; i<k-1; i++){
            maxi = max(maxi , nums[i]);
        }
        if(k==nums.size()){
            return maxi;
        }
        return max(maxi , nums[k]);

    }
};