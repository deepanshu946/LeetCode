class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        int n = nums1.size();
        int temp1 = nums1[n-1];
        int temp2 = nums2[n-1];
        bool check = 1;
        int op=0;
        for(int i=0 ; i<nums1.size()-1 ; i++){
            if(nums1[i] <= temp1 && nums2[i] <= temp2){
                continue;
            }
            else{
                if(nums2[i] <= temp1 && nums1[i] <= temp2){
                op++;
                }
                else{
                    check=0;
                    break;
                }
            }
        }
        if(check){
            ans = min(ans , op);
        }
        swap(temp1,temp2);
        op=1;
        check=1;
        for(int i=0 ; i<nums1.size()-1 ; i++){
            if(nums1[i] <= temp1 && nums2[i] <= temp2){
                continue;
            }
            else{
                if(nums2[i] <= temp1 && nums1[i] <= temp2){
                op++;
                }
                else{
                    check=0;
                    break;
                }
            }
        }
        if(check){
            ans = min(ans , op);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

    }
};