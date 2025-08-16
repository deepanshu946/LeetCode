class Solution {
private:
bool check(int mid, vector<int> &nums , int k , int m){
    int count=0;
    int temp=0;
    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i]<=mid){
            count++;
            if(count==k){
                temp++;
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    return temp>=m;
}
public:
    int minDays(vector<int>& nums, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]);

        }
        int start = mini;
        int end = maxi;
        while(start<=end){
            int mid = (start+end)/2;
            if(check(mid,nums,k,m)){
                end = mid-1;

            }
            else{
                start = mid+1;
            }
        }
        if(start>maxi){
            return -1;
        }
        return start;
    }
};