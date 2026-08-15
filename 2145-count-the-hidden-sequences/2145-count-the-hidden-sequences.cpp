class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        // return -1;
        int maxiind = -1;
        long long maxi = LLONG_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxiind = i;
            }
        }
        cout<<maxiind<<endl;
        long long mini = LLONG_MAX;
        // int miniind= 0;

        maxi = lower;
        long long val = lower;
        for(int i=maxiind ; i<nums.size() ; i++){
            val += nums[i];
            mini = min(mini, val);
            maxi = max(maxi , val);
        }
        val = lower;
        for(int i=maxiind-1 ; i>=0 ; i--){
            val = val - nums[i];
            mini = min(mini, val);
            maxi = max(maxi , val);

        }
        if(maxi > upper){
            return 0;
        }
        long long temp = 0;
        if(mini < lower){
            temp = lower - mini;
        }
        if(upper-maxi+1-temp < 0){
            return 0;
        }
        
        return upper-maxi+1-temp ;
    }
};