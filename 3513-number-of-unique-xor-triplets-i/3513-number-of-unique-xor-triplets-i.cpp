class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans = 1;
        int i = 1;
        
        int n = nums.size();
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        while(n != 0){
            n = n/2;
            ans = ans + i;
            i=i*2;
        }
        return ans;
    }
};