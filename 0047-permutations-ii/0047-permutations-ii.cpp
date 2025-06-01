class Solution {
private:
void solve(vector<int> &nums ,set<vector<int>> &ans , int index, int size){
    if(index>=size){
        ans.insert(nums);
    }
    for(int i=index ; i<size ; i++){
        if(!(i>index && nums[i]==nums[index])){
        swap(nums[i],nums[index]);
        solve(nums, ans , index+1 , size);
        swap(nums[i],nums[index]);
        }
    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        int size = nums.size();
        int index = 0;
        solve(nums , ans , index , size);
        vector<vector<int>> temp;
        for(auto i:ans){
            temp.push_back(i);
        }
        return temp;
    }
};