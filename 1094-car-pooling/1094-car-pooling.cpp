class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr = 0;
        map<int,int> m;
        for(int i=0 ; i<trips.size() ; i++){
            m[trips[i][1]]+=trips[i][0];
            m[trips[i][2]]-=trips[i][0];

        }
        for(auto i:m){
            curr = curr + i.second;
            if(curr > capacity){
                return false;
            }
        }
        return true;
    }
};