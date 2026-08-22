class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        // k = k+1;
        vector<int> ans(n,INT_MAX);
        ans[src]=0;
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0 ; i<flights.size() ; i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({k+1,{0,src}});
        while(!pq.empty()){
            pair<int,pair<int,int>> t = pq.front();
            pq.pop();
            int left = t.first;
            int dist = t.second.first;
            int node = t.second.second;
            if(left==0 && node != dest){
                continue;
            }
            for(auto i:adj[node]){
                if(i.second + dist < ans[i.first] ){
                    ans[i.first] = i.second + dist;
                    pq.push({left-1,{ ans[i.first], i.first}});
                }
            }

        }
        if(ans[dest] == INT_MAX){
            return -1;
        }
        return ans[dest];
    }
};