class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> temp;
        for(int i=0 ; i<tasks.size() ; i++){
            temp.push_back({tasks[i][0],tasks[i][1],i});

        }
        sort(temp.begin(),temp.end());
        long long curr = temp[0][0];
        int i = 1;
        pq.push({temp[0][1],temp[0][2]});
        while(ans.size()<tasks.size()){
            
            while(i<temp.size() && temp[i][0]<=curr){
                pq.push({temp[i][1],temp[i][2]});
                i++;
            }
            if(pq.empty()){
                curr = temp[i][0];
            }
            else{
                curr = curr + pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            }
            
        }
        return ans;

    }
};