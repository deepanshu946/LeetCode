class Solution {
private:
bool checknums(vector<int> &nums , long long k){
    if(k==0){
        return false;
    }
    long long count = 0;
    for(int i=0 ; i<nums.size() ; i++){
        int rem = nums[i]%k;
        count += nums[i]/k;
        if(rem!=0){
            count++;
        }
    }
    if(count <= k*k){
        return true;
    }
    return false;
}
int solve(int start , int end , vector<int> &nums){
    int s = start;
    int n = nums.size();
    int e = max(end,n+1);
    int ans = 0;
    while(s<=e){
        long long mid = (s+e)/2;
        bool check = checknums(nums,mid);
        if(check){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;

}
public:
    int minimumK(vector<int>& nums) {
        // int maxi = 0;
        // for(int i=0 ; i<nums.size(); i++){
        //     maxi = max(maxi,nums[i]);
        // }
        return solve(0,1e5,nums);

    }
};