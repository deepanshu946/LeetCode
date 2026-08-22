class Solution {
private:
bool ans = 1;
void bfs(int i , vector<int> &vis , vector<int> &color , vector<vector<int>> &graph){
    vis[i]=1;
    color[i]=1;
    queue<int> pq;
    pq.push(i);
    int curr = 1;
    while(!pq.empty()){
        int size = pq.size();
        for(int j=0 ; j<size ; j++){
            int t = pq.front();
            pq.pop();
            for(auto neigh : graph[t]){
                if(vis[neigh] && color[neigh]==curr){
                    ans=0;
                    // break;
                }
                else if(!vis[neigh]){
                    vis[neigh]=1;
                    color[neigh]=!curr;
                    pq.push(neigh);
                }
            }
        }
        curr = !curr;
       
        
    }

}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        // bool ans = false;
        for(int i=0 ; i<n ; i++){
            if(!vis[i] ){
                bfs(i,vis,color,graph);
            }
        }
        return ans;
    }
};