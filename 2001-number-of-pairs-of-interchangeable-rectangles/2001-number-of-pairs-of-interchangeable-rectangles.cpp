class Solution {

public:
    long long interchangeableRectangles(vector<vector<int>>& nums) {
        unordered_map<double,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[double(nums[i][0])/(double)nums[i][1]]++;
        }
        long long ans=0;
        for(auto i:m){

            ans = ans + (1LL*i.second*(i.second-1))/2;

        }
        return ans;

    }
};