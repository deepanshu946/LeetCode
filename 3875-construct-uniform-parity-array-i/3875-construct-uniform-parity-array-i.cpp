class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evencount=0;
        int oddcount = 0;
        int evenindex = 0;
        int oddindex = 0;
        for(int i=0 ; i<nums1.size() ; i++){
            if(nums1[i]%2==0){
                evenindex = i;
                evencount++;
            }
            else{
                oddindex=i;
                oddcount++;
            }
        }
        //check for all even
        bool alleven = 1;
        for(int i=0 ; i<nums1.size() ; i++){
            if(nums1[i]%2==0){
                continue;
            }
            if(oddcount == 1){
                if(oddindex == i){
                    alleven = 0;
                }
            }
        }
        //check for all odd
        bool allodd = 1;
        for(int i=0 ; i<nums1.size() ; i++){
            if(nums1[i]%2 != 0){
                continue;
            }
            if(oddcount == 1){
                if(oddindex == i){
                    allodd = 0;
                }
            }
        }
        return alleven|allodd;
    }
};