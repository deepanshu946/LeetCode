class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<edges.size() ; i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(patience.size(),0);
        vector<int> ans(patience.size(),0);
        queue<int> pq;
        pq.push(0);
        int level = 0;
        ans[0]=0;
        vis[0]=1;
        while(!pq.empty()){
            int size = pq.size();
            for(int i=0 ; i<size ; i++){
                int top = pq.front();
                pq.pop();
                ans[top]=level;
                // vis[top]=1;
                for(auto j:m[top]){
                    if(!vis[j]){
                        vis[j]=1;
                        pq.push(j);
                    }
                }
            }
            level++;
        }

        int temp = 0;

        for(int i=1 ; i<ans.size() ; i++){
            
            int time = ans[i]*2;
            temp = max(temp , time+1);
            int steps = time/patience[i];
            if(steps != 0){
                int last = steps*patience[i];
                if(last==time){
                    last = last-patience[i];
                }
                int newtime = last + time;
                temp = max(temp,newtime+1);

            }
        }
        return temp;

    }
};