class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(nums.size(), 0);
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                pre[i] += pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1];
            }
        }
        vector<int> suff(n, 0);
        for (int i = n-2; i>=0; i--) {
            if (nums[i+1] < nums[i]) {
                suff[i] = suff[i + 1] + 1;
            } else {
                suff[i] = suff[i +1];
            }
        }
        vector<int> ans;
        for(int i=k ; i<n-k ; i++){
            if(pre[i-1]-pre[i-k] == 0 && suff[i+1]-suff[i+k]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};