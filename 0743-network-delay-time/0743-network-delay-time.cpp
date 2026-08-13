class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0 ; i<times.size() ; i++){
            m[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> ans(n+1, INT_MAX);
        ans[k]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            for(auto neigh : m[t.second]){
                if(t.first + neigh.second < ans[neigh.first]){
                    ans[neigh.first] = t.first+neigh.second;
                    pq.push({ans[neigh.first],neigh.first});
                }
            }
        }
        int output = INT_MIN;
        for(int i=1 ;i<ans.size() ; i++){
            if(i != k){
                output = max(output , ans[i]);
            }
        }
        if(output == INT_MIN || output == INT_MAX){
            return -1;
        }
        return output;
    }
};