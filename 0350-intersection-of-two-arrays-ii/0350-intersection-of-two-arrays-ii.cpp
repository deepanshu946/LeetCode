class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s;
        // s.insert(nums1.begin(),nums1.end());
        for(int i=0 ; i<nums1.size() ; i++){
            s[nums1[i]]++;
        }
        vector<int> ans;
        for(int i=0 ; i<nums2.size() ; i++){
            if(s.find(nums2[i]) != s.end() && s[nums2[i]] != 0){
                ans.push_back(nums2[i]);
                s[nums2[i]]--;
            }
        }
        return ans;
    }
};