class Solution {
private:
bool dfs(int i , vector<vector<int>> &graph , vector<bool> &vis , vector<bool> &pathvis , vector<int> &ans){
    vis[i]=1;
    pathvis[i]=1;
    // ans[i]=0;
    for(auto it : graph[i]){
        if(!vis[it]){
            if(dfs(it,graph,vis,pathvis,ans)){
                // ans[i]=0;
                return true;
            }
            
        }
        else if(pathvis[it]){
                // ans[i]=0;
                return true;
            }
    }
    ans[i]=1;
    pathvis[i]=0;
    return false;

}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n = graph.size();
        // vector<bool> vis(n,0);
        // vector<bool> pathvis(n,0);
        // vector<int> ans(n,0);
        // for(int i=0 ; i<n ; i++){
        //     if(!vis[i]){
        //         dfs(i,graph,vis,pathvis, ans);
        //     }
        // }
        // vector<int> temp;
        // for(int i=0 ; i<n ; i++){
        //     if(ans[i]==1){
        //         temp.push_back(i);
        //     }
        // }
        // return temp;

        //using topo sort
        //reverse the edges and get all the nodes with indegree 0 and then removeal of edges on adjacent nodes

        unordered_map<int,int> indegree;
        queue<int> q;
        vector<vector<int>> edge(graph.size(),  vector<int>());
        for(int i=0 ; i<graph.size() ; i++){
            indegree[i]+=graph[i].size();
            if(indegree[i]==0){
                q.push(i);
            }
            for(int j=0 ; j<graph[i].size() ; j++){
                edge[graph[i][j]].push_back(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto it : edge[t]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    
        

    }
};