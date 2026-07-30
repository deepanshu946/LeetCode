class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int appendcost = INT_MAX;
        long long cost = 0;
        bool flag = 0;
        int last = nums2[nums2.size()-1];
        for(int i=0 ; i<nums1.size() ; i++){
            cost += abs(nums1[i]-nums2[i]);
            if(!flag){
                if(nums1[i]>nums2[i]){
                    if(last > nums2[i] && last< nums1[i]){
                        appendcost = 1;
                        flag = 1;
                    }
                    else{
                        appendcost = min(appendcost ,1+ min(abs(nums1[i]-last),abs(nums2[i]-last)));
                    }
                }
                else{
                    if(last > nums1[i] && last< nums2[i]){
                        appendcost = 1;
                        flag = 1;
                    }
                    else{
                        appendcost = min(appendcost ,1+ min(abs(nums1[i]-last),abs(nums2[i]-last)));
                    }
                }
            }
            
        }
        return cost + appendcost;
    }
};