class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        // for(int i=0 ; i<nums.size() ; i++){
        //     m[nums[i]]++;
        // }
        int ans = 0;
        unordered_set<int> s1;
        unordered_set<int> s2;

        for(int i=0 ; i<nums.size() ; i++){
            // if(m.find(nums[i])==m.end()){
                if(m.find(nums[i]-k) != m.end()){
                    ans += 1;
                    // s1.insert(nums[i]);

                }
                if(k==0 ){
                    if(m[nums[i]]>1) ans++;
                    ans += 1;
                    // s2.insert(nums[i]);

                }
            // }
            
            m[nums[i]]++;
        }
        return ans;
    }
};