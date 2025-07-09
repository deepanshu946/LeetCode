class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        sort(nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
                int diff = nums2[0]-nums1[0];
                bool check = 1;
                for(int k=1 ; k<nums2.size() ; k++){
                    if(nums2[k]-nums1[k] != diff){
                        check=0;
                        break;
                    }
                }  
                if(check){
                    return diff;
                } 
        return -1;
    }
};