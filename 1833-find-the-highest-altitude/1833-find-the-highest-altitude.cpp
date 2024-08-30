class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefix = gain[0];
        int ans = max(0,gain[0]);
        for(int i=1 ; i<gain.size() ; i++){
            prefix = prefix + gain[i];
            ans = max(ans , prefix);
        }
        return ans;
    }
};