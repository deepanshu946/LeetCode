class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                int prod = nums[i]*nums[j];
                m[prod]++;
            }
        }
        int ans = 0;
        for(auto arr:m){
            int n = arr.second;
            ans = ans + 8*((n-1)*(n)/2);
        }
        return ans;
        
    }
};