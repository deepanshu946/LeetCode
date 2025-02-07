class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int left=0;
        int right = 0;
        int t=0;
        int ans = 0;
        while(right<nums.length()){
            if(nums[right]=='F'){
                t++;
            }
            if(t<=k){
                ans = max(ans , right-left+1);
            }
            else{
                while(t>k){
                    if(nums[left]=='F'){
                        t--;
                    }
                    left++;
                }
            }
            right++;
        }
        left=0;
        right = 0;
        t=0;
        while(right<nums.length()){
            if(nums[right]=='T'){
                t++;
            }
            if(t<=k){
                ans = max(ans , right-left+1);
            }
            else{
                while(t>k){
                    if(nums[left]=='T'){
                        t--;
                    }
                    left++;
                }
            }
            right++;
        }

        return ans;
    }
};