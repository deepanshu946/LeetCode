class Solution {
private:
void solve(int i , vector<int> &vis , unordered_map<int,vector<int>> &m){
    vis[i]=1;
    for(auto neigh:m[i]){
        if(!vis[neigh]){
            solve(neigh,vis,m);
        }
    }
}
vector<int> parent;
vector<int> rank;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x , int y){
    
    int x_parent = find(x);
    int y_parent = find(y);
    if(x_parent==y_parent){
        return ;
    }
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
    
    
    
    
}
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0;
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<connections.size() ; i++){
            m[connections[i][0]].push_back(connections[i][1]);
            m[connections[i][1]].push_back(connections[i][0]);

        }
        vector<int> vis(n,0);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                ans++;
                solve(i,vis,m);
            }
        }
        // cout<<ans;
        // return ans;
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i]=i;
        }
        int temp =0;
        for(int i=0 ;i<connections.size() ; i++){
            if(find(connections[i][0])==find(connections[i][1])){
                temp++;
            }
            else{
                Union(connections[i][0],connections[i][1]);
            }
        }
        if(temp<ans-1){
            return -1;
        }
        return ans-1;
    }
};