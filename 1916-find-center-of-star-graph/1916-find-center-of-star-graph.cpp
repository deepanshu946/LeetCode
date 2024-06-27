class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        m[edges[0][0]]++;
        m[edges[0][1]]++;
        for(int i=1 ; i<edges.size() ; i++){
            if(m.find(edges[i][0]) != m.end() ){
                m[edges[i][0]]++;
            }
            if(m.find(edges[i][1]) != m.end() ){
                m[edges[i][1]]++;
            }
        }
        if(m[edges[0][0]] == edges.size()){
            return edges[0][0];
        }
        else{
            return edges[0][1];
        }
    }
};