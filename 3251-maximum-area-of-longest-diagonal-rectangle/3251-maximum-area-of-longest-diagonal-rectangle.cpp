class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        int ans = 0;
        int maxi = 0;
        for(int i=0 ; i<nums.size() ; i++){
            long long hyp = (nums[i][0]*nums[i][0]) + (nums[i][1]*nums[i][1]);
            if(hyp > maxi){
                ans = nums[i][0]*nums[i][1];
                maxi = max(maxi,(int)hyp);
            }
            if(hyp == maxi){
                ans = max(ans , nums[i][0]*nums[i][1]);
            }

        }
        return ans;
    }
};