class Solution {
private:
void solve(vector<int> &nums , int target , int start , int n , vector<vector<int>> &ans , vector<int> &temp){
    if(target<0){
        return ;
    }
    if(target==0){
        ans.push_back(temp);
        return;
    }
        for(int j=start ; j<n ; j++){
            temp.push_back(nums[j]);
            solve(nums,target-nums[j] ,j, n , ans,temp);
            temp.pop_back();
        }
}
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(candidates,target,0,n,ans,temp);
        return ans;

    }
};