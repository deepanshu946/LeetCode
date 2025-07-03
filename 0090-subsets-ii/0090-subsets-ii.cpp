class Solution {
private:
void solve(int i , set<vector<int>> &s , vector<int> &nums , vector<int> &temp){
    if(i>=nums.size()){
        // sort(temp.begin(),temp.end());
        s.insert(temp);
        // temp.clear();
        return;
    }
    temp.push_back(nums[i]);
    solve(i+1,s,nums,temp);
    temp.pop_back();
    solve(i+1,s,nums,temp);
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        solve(0,s,nums ,temp);
        vector<vector<int>> ans;
        set<vector<int>> s2;

        for(auto i:s){
            vector<int> temp2 =i;
            sort(temp2.begin(),temp2.end());
            // s.erase(i);
            s2.insert(temp2);
        }
        for(auto i:s2){
            ans.push_back(i);
        }
        return ans;
        
    }
};