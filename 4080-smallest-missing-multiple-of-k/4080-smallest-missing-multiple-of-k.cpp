class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=1 ; 
        unordered_set<int> s(nums.begin(),nums.end());
        while(true){
            if(s.find(k*i) != s.end()){
                i++;
                continue;
            }
            else{
                return k*i;
            }
        }
        return 0;
    }
};