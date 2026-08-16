class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int,int>> st;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1 ; i>=0 ; i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top().second - i;

            }
            st.push({nums[i],i});
        }
        return ans;
    }
};