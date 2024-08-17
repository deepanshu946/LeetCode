class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i=0 ; i<nums.size()-k+1 ; i++){
            int maxi=nums[i];
            bool flag=0;
            for(int j=i ; j<k+i-1 ; j++){
                if(nums[j+1]-nums[j] != 1){
                    ans.push_back(-1);
                    flag = 1;
                    break;
                }
                maxi=max(maxi,max(nums[j],nums[j+1]));
            }
            if(!flag){
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};