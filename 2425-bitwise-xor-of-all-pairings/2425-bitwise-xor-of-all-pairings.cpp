class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        for(int i=0 ; i<nums1.size() ; i++){
            xor1 = xor1^nums1[i];
        }
        cout<<xor1<<endl;
        int xor2 = 0;
        for(int i=0 ; i<nums2.size() ; i++){
            xor2 = xor2^nums2[i];
        }
        if(nums1.size() %2 ==0 && nums2.size() %2 ==0){
            return 0;
        }
        else if(nums1.size() %2 ==0 && nums2.size() %2 !=0){
            return xor1;
        }
        else if(nums1.size() %2 !=0 && nums2.size() %2 ==0){
            return xor2;
        }
        return xor1^xor2;
    }
};