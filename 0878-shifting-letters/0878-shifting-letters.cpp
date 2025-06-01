class Solution {
public:
    string shiftingLetters(string s, vector<int>& nums) {

        for(int i=nums.size()-2 ; i>=0 ; i--){
            nums[i]=nums[i]+(nums[i+1])%26;
        }
        // return s;
        for(int i=0 ; i<nums.size() ; i++){
            nums[i]=nums[i]%26;
            if('z'-s[i] < nums[i]){
                s[i]='a'+(nums[i] - ('z'-s[i])) - 1;
            }
            else{
                 s[i]=s[i]+nums[i];

            }
        }
        return s;
    
    }
};