class Solution {
private:
int solve(int start , int end , vector<int> &nums , int k){
    long long val = nums[start];
    val = val*k;
    int store = -1;
    while(start <= end){
        int mid = (start + end)/2;
        if(nums[mid]>val){
            end = mid-1;
        }
        else{
            store = mid;
            start = mid+1;
        }
    }
    return start;
}
public:
    int minRemoval(vector<int>& nums, int k) {  
        sort(nums.begin(),nums.end());
        // unordered_map<int,int> m;/
        // return 0;
        long long ans = INT_MAX;
        for(int i=0 ; i<nums.size() ; i++){
            int index = solve(i,nums.size()-1 , nums, k);
            if(i+ nums.size() -index+1 < ans){
                ans = i+ nums.size() -index+1;
            }
        }
        return ans-1;
        

    }
};