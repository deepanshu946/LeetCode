class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int i=0 ; i<rolls.size() ; i++){
            sum = sum + rolls[i];
        }
        int remainder = mean*(n+m) - sum;
        int common = remainder/n;
        remainder = remainder - (common*n);
        if((common == 6 && remainder != 0) || common>6 || common <= 0){
            return {};
        }
        vector<int> ans(n,common);
        int i=0;
        while(remainder != 0){
            ans[i]++;
            remainder--;
            i = (i+1)%n;
        }
        return ans;
    }
};