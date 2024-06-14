class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            int num = nums[i];
            int sum=0;
            while(num!=0){
                int digit = num%10;
                num=num/10;
                sum = sum+digit;
            }
            m[sum].push_back(nums[i]);
        }
        int ans = -1;
        for(pair<int,vector<int>> i:m){
            if(i.second.size() > 1){
                vector<int> temp = i.second;
                sort(temp.begin() , temp.end());
                int n = temp.size();
                ans = max(ans,temp[n-1]+temp[n-2]);
            }
        }
        return ans;
    }
};