class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]=1;
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