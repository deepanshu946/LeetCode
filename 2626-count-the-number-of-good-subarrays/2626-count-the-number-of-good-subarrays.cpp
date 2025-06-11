class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans =0;
        int count=0;
        int left=0;
        int right = 0;
        unordered_map<int,int> m;
        while(right<nums.size()){
            if(count>=k){
                while(count>=k && left<=right){
                    count = count - ((m[nums[left]] * (m[nums[left]]-1))/2);
                    m[nums[left]]--;
                    count = count + ((m[nums[left]] * (m[nums[left]]-1))/2);
                    left++;
                    ans = ans + nums.size()-right+1;
                }
            }
            else{
                if(m.find(nums[right]) != m.end()){
                    count = count - ((m[nums[right]]*(m[nums[right]]-1))/2);
                }
                m[nums[right]]++;
                count = count + ((m[nums[right]]*(m[nums[right]]-1))/2);
                right++;
            }
        }
        if(count>=k){
                while(count>=k && left<=right){
                    count = count - ((m[nums[left]] * (m[nums[left]]-1))/2);
                    m[nums[left]]--;
                    count = count + ((m[nums[left]] * (m[nums[left]]-1))/2);
                    left++;
                    ans = ans + nums.size()-right+1;
                }
            }
        return ans;
    }
};