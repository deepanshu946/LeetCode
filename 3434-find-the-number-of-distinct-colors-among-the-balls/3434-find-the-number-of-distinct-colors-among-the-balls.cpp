class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balltocolor;
        unordered_map<int,unordered_set<int>> color;
        vector<int> ans;
        for(int i=0 ; i<queries.size() ; i++){
            int ball = queries[i][0];
            int colorr = queries[i][1];
            if(balltocolor.find(ball)== balltocolor.end()){
                balltocolor[ball]=colorr;
                color[colorr].insert(ball);
            }
            else{
                int tempcolor = balltocolor[ball];
                color[tempcolor].erase(ball);
                if(color[tempcolor].size()==0){
                    color.erase(tempcolor);
                }
                balltocolor[ball]=colorr;
                color[colorr].insert(ball);

            }
            ans.push_back(color.size());

        }
        return ans;
    }
};