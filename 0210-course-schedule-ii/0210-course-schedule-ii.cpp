class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> edge(V,vector<int>());
        for(int i=0 ; i<edges.size() ; i++){
            edge[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indeg(V,0);
        for(int i=0 ; i<edges.size() ; i++){
            
            indeg[edges[i][1]]++;
            
       
        }
        queue<int> q;
        for(int i=0 ; i<indeg.size() ; i++){
            if(indeg[i]==0){
                q.push(i);
            }
            
        }
        vector<int> ans;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            for(auto it:edge[t]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size() != V){
            return {};
        }
        return ans;
        
    }
};