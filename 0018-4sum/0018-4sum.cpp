class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0 ; i<n ; i++){
            if( i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1 ; j<n ; j++){
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int start = j+1;
                int end = n-1;
                long long sum = nums[i]+nums[j];
                long long left = target - sum;
                while(start<end){
                    if(nums[start] + nums[end]==left){
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        
                        start++;
                        end--;
                        while(start<end && nums[start]==nums[start-1]){
                            start++;
                        }
                        while(end!=n-1 && start<end && nums[end]==nums[end+1]){
                            end--;
                        }
                    }
                    else if(nums[start]+nums[end]<left){
                        start++;
                    }
                    else{
                        end--;
                    }
                }

            }
        }
        return ans;
    }
};