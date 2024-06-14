class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int> pq;
        map<int,vector<int>> m;
        for(int i=0 ; i<k ; i++){
            int dist =((points[i][0])*(points[i][0]))+((points[i][1])*(points[i][1]));
            pq.push(dist);
            m[dist].push_back(i);
        }
        for(int i=k ; i<points.size() ; i++){
            int dist =((points[i][0])*(points[i][0]))+((points[i][1])*(points[i][1]));
            if(dist<pq.top()){
                pq.pop();
                pq.push(dist);
                m[dist].push_back(i);
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            for(int i=0 ; i<m[top].size() ; i++){

                ans.push_back(points[m[top][i]]);
            }
            m[top].clear();
        }
        return ans;

        
    }
};