class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int mask = 0 ; mask<(1<<n) ; mask++){
            vector<int> temp;
            bool check=0;
            for(int i=0 ; i<n ; i++){
                if(mask & (1<<i)){
                    if(i>0 && nums[i]==nums[i-1] && !(mask&(1<<(i-1)))){
                        check=1;
                        break;
                    }
                    temp.push_back(nums[i]);
                }

            }
            if(!check){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};