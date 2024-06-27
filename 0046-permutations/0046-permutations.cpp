class Solution {
private:
void solve(vector<int> nums,vector<vector<int>>& ans,int index, int size){
    //base case
    if(index>=size){
        ans.push_back(nums);
        return;
    }

    //swap the values and increase index 
    for(int j=index ; j<size ; j++){
        swap(nums[index],nums[j]);
        solve(nums , ans , index+1, size);
        //backtracing 
        swap(nums[index],nums[j]);
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        int index = 0;
        solve(nums , ans , index, size);
        return ans;
    }
};