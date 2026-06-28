class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto i:m){
            if(i.second==1){
                return -1;
            }
            int temp = i.second;
            int three = temp/3;
            int rem = temp%3;
            if(rem==0){
                ans+= three;
            }
            else if(rem==1){
                three--;
                ans += three+2;
            }
            else{
                ans += three+1;
            }
        }
        return ans;
    }
};