class Solution {
private:
int solve(vector<int> &nums , int end , int start){
    int prev2 = 0;
    int prev1=nums[start];
    for(int i=start+1 ; i<=end ; i++ ){
        int curr = max(prev2+nums[i],prev1);
        prev2 = prev1;
        prev1=curr;

    }
    return prev1;
    
}
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        //including first house and excluding last
        //start = 0; end = n-2
        int first = solve(nums,n-2,0);
        //excluding first and including last
        //start = 1 ; end = n-1
        int last= solve(nums,n-1,1);
        return max(first,last);
    }
};