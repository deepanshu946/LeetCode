class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int maxx = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            maxx = max(nums[i],maxx);
        }
        int start = 1;
        int end = maxx;
        int store = 0;
        while(start<=end){
            int mid= (start+end)/2;
            long long temp = 0;
            for(int i=0 ; i<nums.size() ; i++){
                temp = temp+ (nums[i]/mid);
                if(nums[i]%mid != 0){
                    temp++;
                }
            }
            if(temp>h){
                start = mid+1;
            }
            else{
                // store = mid;
                end = mid-1;
            }
        }
        return start;
    }
};