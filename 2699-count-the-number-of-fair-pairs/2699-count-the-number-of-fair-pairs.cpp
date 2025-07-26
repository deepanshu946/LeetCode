class Solution {
private:
int lower_bound(vector<int> &nums , int target){
    int start = 0;
    int end = nums.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]>target){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int> &nums , int target){
    int start = 0;
    int end = nums.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(nums[mid]>=target){
            ans = mid;
            end = mid-1;
        }
        else{
            // ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            int end = lower_bound(nums,upper-nums[i]);
            int start =upper_bound(nums,lower-nums[i]);
            cout<<start<<" "<<end<<endl;
            if(end != -1 && start != -1 && start<=end){
                 ans = ans + (end-start+1);
            if(i>=start && i<=end){
                ans--;
            }
            }
           
        }
        return ans/2;
    }
};