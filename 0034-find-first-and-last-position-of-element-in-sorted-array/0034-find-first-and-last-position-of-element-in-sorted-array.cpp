class Solution {
private:
int getfirst(vector<int> &nums , int target){
    int ans = -1;
    int start = 0;
    int end = nums.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]==target){
            ans= mid;
            end=mid-1;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int getlast(vector<int> &nums , int target){
    
    int ans = -1;
    int start = 0;
    int end = nums.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]==target){
            ans= mid;
            start=mid+1;
        }
        else if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
        return {-1,-1};
        }
        int a = getfirst(nums,target);
        int b = getlast(nums,target);
        return {a,b};
    }
};