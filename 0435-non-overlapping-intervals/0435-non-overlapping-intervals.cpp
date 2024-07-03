class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int ans = 0;
        vector<int> prev = intervals[0];
        for(int i=1 ; i<intervals.size() ; i++ ){
            if(intervals[i][0]<prev[1]){
                if(intervals[i][1]<prev[1]){
                    prev = intervals[i];
                }
                ans++;
            }
            else{
                prev = intervals[i];
            }
        }
        return ans;
    }
};