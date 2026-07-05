class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // sort(logs.begin(),logs.end());
        int maxi = 0;
        int ans = 0;
        int curr=0;
        vector<pair<int,int>> temp;
        for(int i=0 ; i<logs.size() ; i++){
            temp.push_back({logs[i][0],1});
            temp.push_back({logs[i][1],-1});

        }
        sort(temp.begin(),temp.end());
        for(int i=0 ;i<temp.size() ; i++){
            curr = curr + temp[i].second;
            if(curr>maxi){
                maxi = curr;
                ans = temp[i].first;
            }
        }
        return ans;
    }
};