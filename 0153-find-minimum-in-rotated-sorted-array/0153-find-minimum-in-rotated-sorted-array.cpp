class Solution {
private:

public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        if(nums[start] <= nums[end]){
            return nums[start];
        }
        while(start<end){
            int mid = (start+end)/2;
 
            if(mid==0 || mid==n-1){
                return nums[n-mid-1];
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1] && nums[mid]>nums[0]){
                //1st line
                start = mid;
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1] && nums[mid]<nums[0]){
                end = mid;
            }
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return nums[mid+1];
            }
            else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
        }
        return  0;
    }
};