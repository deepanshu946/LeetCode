class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        s.insert(nums.begin(),nums.end());
        for(int i=0 ; i<nums.size() ; i++){
            int rev=0;
            int num = nums[i];
            while(num != 0){
                int digit = num%10;
                rev = (rev*10)+digit;
                num=num/10;
            }
            s.insert(rev);
        }
        return s.size();
    }
};