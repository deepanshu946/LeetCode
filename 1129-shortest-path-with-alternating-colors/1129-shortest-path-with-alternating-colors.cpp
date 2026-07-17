class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<int> ans(n, INT_MAX);
        unordered_map<int, vector<int>> blue;
        unordered_map<int, vector<int>> red;
        for (int i = 0; i < redEdges.size(); i++) {
            // if(redEdges[i][0]==redEdges[i][1] && redEdges[i][1]==0){
            //     continue;
            // }
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            if (blueEdges[i][0] == blueEdges[i][1] && blueEdges[i][1] == 0) {
                continue;
            }
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        vector<vector<int>> vis(n, vector<int>(3, 0));
        queue<pair<int, int>> pq;
        pq.push({0, -1});
        int level = 0;
        while (!pq.empty()) {
            int s = pq.size();
            for (int size = 0; size < s; size++) {
                pair<int, int> top = pq.front();
                pq.pop();
                int i = top.first;
                int color = top.second;
                ans[i] = min(ans[i],level);
                if (color == 1) {
                    // red
                    for (auto neigh : blue[i]) {
                        if (vis[neigh][2]==0) {
                            vis[neigh][2]=1;
                            pq.push({neigh, 2});
                        }
                    }
                } else if (color == 2) {
                    // blue
                    for (auto neigh : red[i]) {

                        if (vis[neigh][1] == 0) {
                            vis[neigh][1]=1;
                            pq.push({neigh, 1});
                        }
                    }
                } else {
                    for (auto neigh : red[i]) {
                        if (vis[neigh][1]==0) {
                            vis[neigh][1]=1;
                            pq.push({neigh, 1});
                        }
                    }
                    for (auto neigh : blue[i]) {
                        if (vis[neigh][2]==0) {
                            vis[neigh][2]=1;
                            pq.push({neigh, 2});
                        }
                    }
                }
            }
            level++;
        }
        for(int i=0 ;i<n ; i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
};