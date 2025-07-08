class Solution {
private:
bool dfs(int i , vector<vector<int>> &graph , vector<bool> &vis , vector<bool> &pathvis , vector<int> &ans){
    vis[i]=1;
    pathvis[i]=1;
    ans[i]=0;
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
        int n = graph.size();
        vector<bool> vis(n,0);
        vector<bool> pathvis(n,0);
        vector<int> ans(n,0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis, ans);
            }
        }
        vector<int> temp;
        for(int i=0 ; i<n ; i++){
            if(ans[i]==1){
                temp.push_back(i);
            }
        }
        return temp;

    }
};