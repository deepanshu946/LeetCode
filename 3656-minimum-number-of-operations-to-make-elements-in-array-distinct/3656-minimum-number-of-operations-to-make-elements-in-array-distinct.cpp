class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> m ;
        int far=-1;
        for(int i=nums.size()-1; i>=0 ; i--){
            if(far != -1){
                break;
            }
            if(m.find(nums[i]) != m.end()){
                far = i;
            }
            m[nums[i]]++;
        }
        // cout<<far<<endl;
        far++;
        if(far==0){
            return 0;
        }
        if(far % 3 ==0){
            return far/3;
        }
        else{
            return (far/3) + 1;
        }
    }
};