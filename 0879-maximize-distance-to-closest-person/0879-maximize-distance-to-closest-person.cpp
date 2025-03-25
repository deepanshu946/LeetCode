class Solution {
private:
int solve1(vector<int> &nums , int index){
    if(index<0){
        return 1e9;
    }
    if(nums[index]==1){
        return 0;
    }
    return 1+solve1(nums,index-1);
}
int solve2(vector<int> &nums , int index){
    if(index>=nums.size()){
        return 1e9;
    }
    if(nums[index]==1){
        return 0;
    }
    return 1+solve2(nums,index+1);
}
public:
    int maxDistToClosest(vector<int>& nums) {
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                ans = max(ans , min(solve1(nums,i) , solve2(nums,i)));
            }
        }
        return ans;
    }
};