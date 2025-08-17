class Solution {
private:
bool check(int mid , vector<int> &nums , int k){
    int count = 0;
    int temp = 0;
    for(int i=0 ; i<nums.size() ; i++){
        temp = temp+nums[i];
        if(temp>mid){
            count++;
            temp = nums[i];
        }
    }

    if(count<k){
        return 1;
    }
    return 0;
}
public:
    int shipWithinDays(vector<int>& nums, int k) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            maxi = max(maxi,nums[i]);
        }
        if(k==1){
            return sum;
        }
        int start = maxi;
        int end = sum;
        int store = 0;
        while(start<=end){
            int mid = (start+end)/2;
            if(check(mid,nums,k)){
                store=mid;
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return store;
    }
};