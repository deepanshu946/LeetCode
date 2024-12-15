class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int curr = 0;
        int ans = INT_MAX;
        for(int i=0 ; i<events.size() ; i++){
            if(i==0){
                curr=events[i][1];
                ans = min(ans , events[i][0]);
            }
            else if(events[i][1]-events[i-1][1] > curr){
                curr=events[i][1]-events[i-1][1];
                ans = events[i][0];
            }
            else if(events[i][1]-events[i-1][1] == curr){
                ans = min(ans , events[i][0]);
            }
            
        }
        return ans;
    }
};