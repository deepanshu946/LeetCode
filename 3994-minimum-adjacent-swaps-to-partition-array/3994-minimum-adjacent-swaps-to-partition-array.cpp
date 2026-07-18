class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int first = 0;
        int mid = 0;
        int last = 0;
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>b){
                last++;
            }
            else if(nums[i]<=b && nums[i]>=a){
                ans = (ans + last)%1000000007;
                mid++;
            }
            else{
                ans = (ans + last + mid)%1000000007;
                first++;
            }
        }
        return ans%1000000007;
    }
};