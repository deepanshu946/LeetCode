class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        vector<pair<int,int>> temp(nums.size(),{0,0});
        temp[nums.size()-1]={nums[nums.size()-1],nums[nums.size()-1]};
        for(int i=nums.size()-2; i>=0 ; i--){
            int pos = max(nums[i],temp[i+1].first);
            int neg = min(nums[i],temp[i+1].second);
            temp[i]={pos,neg};
            // cout<<pos<<" "<<neg<<endl;
        }
        // return 0;
        long long ans = LLONG_MIN;
        for(int i=0 ; i<nums.size()-m+1 ; i++){
            pair<long long,long long> next = temp[i+m-1];
            ans = max(ans , max(next.first*nums[i],next.second*nums[i]));
        }
        return ans;
    }
};