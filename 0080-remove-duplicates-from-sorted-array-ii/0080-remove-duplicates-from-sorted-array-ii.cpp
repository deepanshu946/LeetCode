class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0 ; i<n ; i++){
            m[nums[i]]++;
            if(m[nums[i]]>2){
                nums[i]=INT_MAX;
                count++;
            }
        }       
        sort(nums.begin(),nums.end());
        return n-count;

    }
};