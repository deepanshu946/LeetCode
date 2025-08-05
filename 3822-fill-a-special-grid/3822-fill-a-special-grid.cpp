class Solution {
private:
int temp=0;
void solve(int i , int j,vector<vector<int>> &nums , int n){
    if(n==1){
        nums[i][j]=temp;
        temp++;
        return;
    }
    solve(i,j+(n/2),nums,n/2);
    solve(i+(n/2),j+(n/2),nums,n/2);
    solve(i+(n/2),j,nums,n/2);
    solve(i,j,nums,n/2);
}
public:
    vector<vector<int>> specialGrid(int n) {
        
        vector<vector<int>> nums(pow(2,n),vector<int>(pow(2,n),0));
        if(n==0){
            return nums;
        }
        // cout<<nums.size();
        solve(0,nums.size()/2,nums,nums.size()/2);
        solve(nums.size()/2,nums.size()/2,nums,nums.size()/2);
        solve(nums.size()/2,0,nums,nums.size()/2);
        solve(0,0,nums,nums.size()/2);
        return nums;


    }
};