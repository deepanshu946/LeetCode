class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>0){
                m[nums[i]]=1;
            }
        }
        int i=1;
        while(true){
            if(m.find(i)==m.end()){
                return i;
            }
            else{
                i++;
            }
        }
    }
};