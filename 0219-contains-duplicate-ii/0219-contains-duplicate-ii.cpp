class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            //index not linked
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=i;
            }
            else{
                int index = m[nums[i]];
                if(abs(i-index)<=k){
                    return true;
                }
                else{
                    m[nums[i]]=i;
                }
            }
        } 
        return false;
    }
};