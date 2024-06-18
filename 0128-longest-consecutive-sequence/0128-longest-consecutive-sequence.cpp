class Solution {
private:

public:
    int longestConsecutive(vector<int>& nums) {

        map<int,bool> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]=1;
        }
        unordered_map<int,int> m2;
        int ans = 0;
        for(auto i:m){
            int val = i.first;
            if(m.find(val-1) == m.end()){
                m2[val]=1;
            }
            else{
                //val-1 present in nums
                m2[val]=1+m2[val-1];
            }

        ans = max(ans,m2[val]);

        }
        return ans;
    }
};