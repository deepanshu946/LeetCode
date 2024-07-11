class Solution {
private:
int search(vector<int> &nums , int index , int target){
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        int mid =(s+e)/2;
        if(mid != index && nums[mid]==target){
            return mid;
        }
        else if(nums[mid] > target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(search(nums,i,target-nums[i]) != -1){
                ans.push_back(i+1);
                ans.push_back(search(nums,i,target-nums[i])+1);
                return ans;
            }

        }
        return ans;
        
    }
};