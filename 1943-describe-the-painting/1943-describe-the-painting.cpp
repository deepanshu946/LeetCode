class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> m;
        for(int i=0 ; i<segments.size() ; i++){
            m[segments[i][0]]+=segments[i][2];
            m[segments[i][1]]-=segments[i][2];
        }
        int start = 0;
        vector<vector<long long>> ans;
        long long curr = 0;
        for(auto i:m){
            if(curr ==0){
                start = i.first;
                curr += i.second;
            }
            else{
                ans.push_back({start,i.first,curr});
                curr += i.second;
                start = i.first;
            }
        }
        return ans;
    }
};