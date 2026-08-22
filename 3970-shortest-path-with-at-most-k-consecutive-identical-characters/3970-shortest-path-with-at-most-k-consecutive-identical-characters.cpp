class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string label, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq; //dist,k,node
        pq.push({0,{0,0}});
        // vector<int> dist(n,INT_MAX);
        vector<vector<int>> dist(
            n, vector<int>(k, INT_MAX)
        );
        dist[0][0]=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> t = pq.top();
            pq.pop();
            int d = t.first;
            int currk = t.second.first;
            int node = t.second.second;
            if(node == n - 1){
                return d;
            }
            for(auto i:adj[node]){
                int newk = currk;
                if(label[node] == label[i.first]){
                    newk = newk+1;
                }
                else{
                    newk = 0;
                }
                if(newk==k){
                    continue;
                }
                if(d + i.second < dist[i.first][newk]){
                    dist[i.first][newk]=d+i.second;
                    pq.push({dist[i.first][newk],{newk,i.first}});
                }
            }
        }
        // if(dist[n-1][0]==INT_MAX){
            return -1;
        // }
        // return dist[n-1][0];

    }
};