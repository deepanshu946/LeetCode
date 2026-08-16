class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> st;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            st.push({nums[i],i});
        }
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1 ; i>=0 ; i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top().first;
            }
            st.push({nums[i],i});
        }
        return ans;
    }
};