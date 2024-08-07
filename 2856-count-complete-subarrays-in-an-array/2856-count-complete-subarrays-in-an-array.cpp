class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        int ans = 0;
        s1.insert(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i ; j<nums.size() ; j++){
                s2.insert(nums[j]);
                if(s2.size()==s1.size()){
                    ans++;
                }
            }
            s2.clear();
        }
        return ans;
    }

};