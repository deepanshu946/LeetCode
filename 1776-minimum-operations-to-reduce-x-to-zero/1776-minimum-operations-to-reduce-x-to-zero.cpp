class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
        }
        if(x>sum){
            return -1;
        }
        if(sum==x){
            return n;
        }
        int val = sum - x;
        int left = 0;
        int right = 0;
        int len = 0;
        int temp = 0;
        while(right<n){
            temp = temp + nums[right];
            while(temp>val){
                temp = temp - nums[left];
                left++;
            }
            if(temp==val){
                len = max(len , right-left+1);
            }
            right++;
        }
        if(len==0){
            return -1;
        }
        return n - len;
    }
};