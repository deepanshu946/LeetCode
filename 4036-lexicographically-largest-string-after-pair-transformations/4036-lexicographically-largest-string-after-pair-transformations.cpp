class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i=0 ; i<nums.size() ; i++){
            int val = nums[i];
            string temp = "";
            int count = 0;

            while(count != 25 && val != 1){
                if(val%2 != 0){
                    val--;
                    temp.push_back('a'+count);
                    
                }
                val = val/2;
                count++;
            }
            while(val--){
                temp.push_back('a'+count);
            }
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};