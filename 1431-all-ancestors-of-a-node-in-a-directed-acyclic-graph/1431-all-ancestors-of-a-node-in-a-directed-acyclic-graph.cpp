class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int,set<int>> m;
        for(int i=0 ; i<edges.size() ;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            m[v].insert(u);
        }
        vector<vector<int>> ans(n);
        for(int i=0 ; i<n ; i++){
            queue<int> q;
            vector<bool> vis(n,0);
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto j : m[node]){
                    if(vis[j] ==0){
                        q.push(j);
                        vis[j]=1;
                        ans[i].push_back(j);
                    }
                }
            }
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;

        
        
    }
};