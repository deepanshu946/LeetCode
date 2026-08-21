class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(int i=0 ; i<edges.size() ; i++){
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0],edges[i][2]*2});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> t = pq.top();
            pq.pop();
            int cost = t.first;
            int node = t.second;
            for(auto neigh:m[node]){
                int neighnode = neigh.first;
                int neighcost = neigh.second;
                if(cost + neighcost < ans[neighnode]){
                    ans[neighnode] = cost + neighcost;
                    pq.push({ans[neighnode],neighnode});
                }
            }

        }
        if(ans[n-1]==INT_MAX){
            return -1;
        }
        return ans[n-1];
    }
};