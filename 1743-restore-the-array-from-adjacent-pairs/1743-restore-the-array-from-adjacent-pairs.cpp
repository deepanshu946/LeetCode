class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i][0]].push_back(nums[i][1]);
            m[nums[i][1]].push_back(nums[i][0]);
        }
        int front = -1;
        for(auto i:m){
            if(i.second.size() == 1){
                front = i.first;
                break;
            }
        }
        unordered_set<int> vis;
        vis.insert(front);
        vector<int> ans;
        // ans.push_back(front);
        while(vis.size() != m.size()){
            ans.push_back(front);
            for(auto i:m[front]){
                if(vis.find(i) == vis.end()){
                    vis.insert(i);
                    front = i;
                }

            }
        }
        ans.push_back(front);
        return ans;




    }
};