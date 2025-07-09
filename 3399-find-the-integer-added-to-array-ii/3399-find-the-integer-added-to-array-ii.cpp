class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        sort(nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());

        for(int i=0 ; i<nums1.size() ; i++){
            for(int j=i+1 ; j<nums1.size() ; j++){
                vector<int> temp;
                for(int k=0 ; k<nums1.size() ; k++){
                    if(k != i && k!=j){
                        temp.push_back(nums1[k]);
                    }
                }
                // sort(temp.begin(),temp.end());
                int diff = nums2[0]-temp[0];
                bool check = 1;
                for(int k=1 ; k<nums2.size() ; k++){
                    if(nums2[k]-temp[k] != diff){
                        check=0;
                        break;
                    }
                }  
                if(check){
                    ans = min(ans , diff);
                } 
            }
        }
        return ans;
    }
};