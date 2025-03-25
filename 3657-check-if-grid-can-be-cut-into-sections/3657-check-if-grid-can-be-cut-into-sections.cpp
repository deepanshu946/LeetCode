class Solution {
private:
bool check(vector<vector<int>> &intervals){
     vector<vector<int>> ans;
        int n = intervals.size();
        for(int i=0 ; i<n ; i++){
            if(ans.empty() || intervals[i][0]>=ans.back()[1]){
                ans.push_back(intervals[i]);

            }
            else{
                ans.back()[1]=max(ans.back()[1] , intervals[i][1]);
            }
        }
    
    if(ans.size()>=3){
        return true;
    }
    return false;
}
public:
    bool checkValidCuts(int n, vector<vector<int>>& nums) {
        vector<vector<int>> hor;
        vector<vector<int>> ver;
        for(int i=0 ; i<nums.size() ; i++){
            int a = nums[i][0];
            int b = nums[i][1];
            int c = nums[i][2];
            int d = nums[i][3];
            hor.push_back({b,d});
            ver.push_back({a,c});
        }
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        return check(hor)||check(ver);
        
    }
};