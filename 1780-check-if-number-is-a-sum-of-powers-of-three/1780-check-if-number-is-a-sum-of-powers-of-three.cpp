class Solution {
private:
bool solve(int i , vector<int> &nums , int n){
    if(i>=nums.size()){
        if(n==0){
            return true;
        }
        return false;
    }
    if(n<0){
        return false;
    }
    return solve(i+1,nums,n-nums[i])|solve(i+1,nums,n);
}
public:
    bool checkPowersOfThree(int n) {
        vector<int> nums;
        nums.push_back(1);
        int num = 3;
        while(nums.size() < 18){
            nums.push_back(num);
            num = num *3 ;
        }
        return solve(0,nums,n);
    }
};