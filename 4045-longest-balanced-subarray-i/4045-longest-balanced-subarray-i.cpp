class Solution {
public:
    int longestBalanced(vector<int>& nums) {
       
        int ans = 0;
        for(int i=0 ; i<nums.size() ; i++){
            unordered_set<int> s1;
            unordered_set<int> s2;
            if(nums[i]%2==0){
                s1.insert(nums[i]);
            }
            else{
                s2.insert(nums[i]);
            }
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[j]%2==0){
                s1.insert(nums[j]);
            }
            else{
                s2.insert(nums[j]);
            }
            if(s1.size()==s2.size()){
                ans=max(ans,j-i+1);
            }
            }
        }
        return ans;
    }
};