class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int score = 0;
        int ans = 0;
        while(i<=j){
            if(score == 0 && power < nums[i]){
                return 0;
            }
            else if(power>=nums[i]){
                power = power-nums[i];
                score++;
                i++;
            }
            else if(score>0){
                power = power+nums[j];
                j--;
                score--;
            }
            ans = max(ans , score);
        }
        return ans;
    }
};