class Solution {
private:
int solve(vector<int> &nums){
    int start = 0;
    int end = nums.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid] >= nums[0]){
            start = mid+1;
        }
        else if(nums[mid] < nums[0]){
            end = mid-1;
        }
        
    }
    return start;
}
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size()-1]){
            return nums[0];
        }
        int index = solve(nums);
        return nums[index];
    }
};