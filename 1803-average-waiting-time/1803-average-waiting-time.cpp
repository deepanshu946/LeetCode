class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        int n = nums.size();
        int time = nums[0][0];
        double ans = 0;
        for(int i=0 ; i<n ; i++){
            if(time<nums[i][0]){
                ans = ans +nums[i][1];
                time = nums[i][0]+nums[i][1];
            }
            else{
                time = time + nums[i][1];

                ans = ans+(time-nums[i][0]);
            }
            cout<<ans<<endl;
        }
        return ans/n;

    }
};