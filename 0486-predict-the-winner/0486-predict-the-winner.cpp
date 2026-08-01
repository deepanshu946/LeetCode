class Solution {
private:
bool solve(int turn , int start , int end , vector<int> &nums, int sum1 , int sum2){
    if(start>end){
        if(sum1 >= sum2){
            return true;
        }
        return false;
    }
    bool ans ;
    if(turn ){
        //player 1
        ans = solve(0,start+1,end,nums,sum1+nums[start],sum2) || solve(0,start,end-1,nums,sum1+nums[end],sum2) ;
    }
    else{
         ans = solve(1,start+1,end,nums,sum1,sum2+nums[start]) && solve(1,start,end-1,nums,sum1,sum2+nums[end]) ;
    }
    return ans;
}
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(1,0,nums.size()-1,nums, 0,0);
    }
};