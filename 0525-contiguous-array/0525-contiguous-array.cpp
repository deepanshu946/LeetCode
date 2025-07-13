class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> p(n,0);
        int pref = 0;
        for(int i=n-1 ; i>=0 ; i--){
            if(nums[i]==0){
                pref++;
            }
            else{
                pref--;
            }
            p[i]=pref;
            m[pref]=max(m[pref],i);
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(p[i]==0){
                ans = max( ans , n-i);
            }
            else{
                if(m.find(p[i]) != m.end()){
                    int next = m[p[i]];
                    ans = max(ans , next-i);
                }
            }
        }
        return ans;


    }
};