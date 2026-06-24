class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        unordered_set<int> s(nums.begin(),nums.end());


        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(s.find(nums[i]-1) == s.end()){
                m.insert(nums[i]);
                // ans = max(ans , 1);
            }
        }
        for(auto i:m){
            int num = i;
            int temp = 0;

            while(s.find(num) != s.end()){
                temp++;
                num++;
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};