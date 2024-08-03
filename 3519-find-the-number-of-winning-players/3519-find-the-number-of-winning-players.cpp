class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<pair<int,int>,int> m;
        for(int i=0 ; i<pick.size() ; i++){
            m[{pick[i][0],pick[i][1]}]++;
        }
        unordered_set<int> s;
        for(auto i:m){
            pair<int,int> p=i.first;
            if(i.second > p.first){
                s.insert(p.first);
            }
        }
        return s.size();
    }
};