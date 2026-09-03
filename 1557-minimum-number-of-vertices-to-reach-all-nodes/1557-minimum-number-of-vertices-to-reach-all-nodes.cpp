class Solution {
private:
void solve(vector<int> &vis , int i , unordered_map<int,vector<int>>&m){
    if(m.find(i)==m.end()){
        return;
    }
    for(auto &adj:m[i]){
        if(!vis[adj]){
            vis[adj]=1;
            solve(vis,adj,m);
        }
    }
}
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        vector<int> indegree(n,0);
        for(int i=0 ; i<edges.size() ; i++){
            m[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};