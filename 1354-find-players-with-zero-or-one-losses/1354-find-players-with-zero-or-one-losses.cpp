class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> s;
        map<int,int> m;
        for(int i=0 ; i<matches.size() ; i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            if(m.find(winner)==m.end()){
                s.insert(winner);
            }
            m[loser]++;
            if(s.find(loser) != s.end()){
                s.erase(loser);
            }
        }
        vector<int> win;
        for(auto i:s){
            win.push_back(i);
        }
        vector<int> los;
        for(auto i:m){
            if(i.second==1){
                los.push_back(i.first);
            }
        }
        return {win,los};
    }
};