class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            int num = nums[i];
            int sum=0;
            while(num!=0){
                int digit = num%10;
                num=num/10;
                sum = sum+digit;
            }
            m[sum].push(nums[i]);
        }
        int ans = -1;
        for(pair<int,priority_queue<int>> i:m){
            if(i.second.size() > 1){
                int a = i.second.top();
                i.second.pop();
                int b = i.second.top();
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
};