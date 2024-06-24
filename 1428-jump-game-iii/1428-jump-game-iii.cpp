class Solution {
private:
bool solve(vector<int> &nums , int start , int n,vector<bool> &vis ){
    if(start>=n || start<0){
        return false;
    }
    if(nums[start]==0){
        return true;
    }
    if(vis[start]==1){
        return false;
    }
    vis[start]=1;
    //2calls
    bool plus = solve(nums,start+nums[start],n,vis);
    bool minus = solve(nums , start-nums[start],n,vis);
    return plus||minus;
}
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> s;
        vector<bool> vis(arr.size()+1 ,0);
        return solve(arr,start,arr.size(),vis);
    }
};