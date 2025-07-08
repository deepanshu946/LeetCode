class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        // int curr = 1;
        queue<int> q;
        for(int j=0 ;j<n ; j++){
            if(color[j] == -1){
                color[j]=0;
            q.push(j);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(int i=0 ; i<graph[top].size() ; i++){
                    if(color[graph[top][i]] != -1){
                        if(color[graph[top][i]] == color[top]){
                            return false;
                        } 

                    }
                    else{
                        color[graph[top][i]]=!color[top];
                        q.push(graph[top][i]);
                    }
                }
            }
            }
        }
        return true;
    }
};