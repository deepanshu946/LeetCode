class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int zero = 0;
        for(int i=s.length()-1 ; i>=0 ; i--){
            if(s[i]=='0'){
                zero++;
            }
            if(s[i]=='1'){
                ans = ans + zero;
            }
        }
        return ans;
    }
};