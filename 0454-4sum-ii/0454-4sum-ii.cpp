class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m;
        int n = nums1.size();
        for(int i=0 ; i<nums1.size() ; i++){
            for(int j=0 ; j<n ; j++){
                m[nums1[i]+nums2[j]]++;
            }

        }
        int ans = 0;
        for(int i=0 ; i<nums1.size() ; i++){
            for(int j=0 ; j<n ; j++){
                int val = nums3[i]+nums4[j];
                if(m.find(-val) != m.end()){
                    ans+= m[-val];
                }
            }

        }
        return ans;

    }
};