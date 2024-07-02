class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        int n1 = nums1.size();
        int n2 =  nums2.size();
        
        if(n1>n2){
            for(int i =0 ; i<n2 ; i++){
                for(int j=0 ; j<n1 ; j++){
                    if(nums2[i]==nums1[j]){
                        ans.push_back(nums2[i]);
                        nums1[j]=-1;
                        break;
                    }
                }
            }
        }
        else{
            for(int i =0 ; i<n1 ; i++){
                for(int j=0 ; j<n2 ; j++){
                    if(nums1[i]==nums2[j]){
                        ans.push_back(nums1[i]);
                        nums2[j]=-1;
                        break;
                    }
                }
            }
        }
        return ans;


    }
};