class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp); 
        vector<int> prev = intervals[0];
        int ans = 1;
        for(int i=1 ; i<intervals.size() ; i++){
            if(intervals[i][0] >= prev[0] && intervals[i][0] <=prev[1] && intervals[i][1] <= prev[1]){
               
            }
            else{
                ans++;
                prev = intervals[i];
            }
        }
        return ans;

    }
};