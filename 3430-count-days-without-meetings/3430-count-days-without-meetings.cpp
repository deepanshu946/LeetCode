class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> ans;
        int n = meetings.size();
        for(int i=0 ; i<n ; i++){
            if(ans.empty() || meetings[i][0]>ans.back()[1]){
                ans.push_back(meetings[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1] , meetings[i][1]);
            }
        }
        int count = 0;
        for(int i=0 ; i<ans.size() ; i++){
             count = count + (ans[i][1] - ans[i][0] + 1) ;
        }
        return days - count;
    }
};