class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& movefrom, vector<int>& moveto) {
        set<int> s;
        for(int i=0 ; i<nums.size() ; i++){
            s.insert(nums[i]);
        }
        for(int i=0 ; i<movefrom.size() ; i++){
            s.erase(movefrom[i]);
            s.insert(moveto[i]);
        }
        vector<int> ans;
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};