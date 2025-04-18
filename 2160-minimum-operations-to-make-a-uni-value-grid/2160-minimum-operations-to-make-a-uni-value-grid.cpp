class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size()/2];
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            int temp = abs(mid-nums[i]);
            if(temp%x != 0){
                return -1;
            }
            else{
                ans = ans + (temp/x);
            }
        }
        return ans;
    }
};