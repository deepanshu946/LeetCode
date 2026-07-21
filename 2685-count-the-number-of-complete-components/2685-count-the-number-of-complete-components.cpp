class Solution {
private:
void solve(int i , unordered_map<int,vector<int>> &m , unordered_map<int,int> &indegree , vector<int> &vis , int &count , int &in){
    vis[i]=1;
    in = min(in , indegree[i]);
    count++;
    for(auto neigh : m[i]){
        if(!vis[neigh]){
            solve(neigh,m,indegree,vis,count,in);
        }
    }

}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        vector<int> vis(n,0);
        unordered_map<int,int> indegree;
        for(int i=0 ; i<edges.size() ; i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][1]]++;
            indegree[edges[i][0]]++;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                int count = 0;
                int in = INT_MAX;
                solve(i,m,indegree,vis,count,in);
                if(in == count-1){
                    ans++;
                }
            }

        }
        return ans;
    }
};