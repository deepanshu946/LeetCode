class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        if(n%2==0){
            int ans = 0;
            int val = nums[mid];
            for(int i=0 ; i<nums.size() ; i++){
                ans= ans + (abs(nums[i]-val));
            }
            val = nums[mid-1];
            int temp = 0;
            for(int i=0 ; i<nums.size() ; i++){
                temp= temp + (abs(nums[i]-val));
            }
            return min(temp,ans);
        }
        else{
            int ans = 0;
            int val = nums[mid];
            for(int i=0 ; i<nums.size() ; i++){
                ans= ans + (abs(nums[i]-val));
            }
            return ans;
        }
        return -1;
    }
};