class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:m){
            pair<int,int> p = make_pair(i.second,i.first);
            pq.push(p);
        }
        vector<int> ans;
        while(k--){
            pair<int,int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};