class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int,string> m;
        for(int i=0 ; i<heights.size() ; i++){
            m[heights[i]]=names[i];
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};