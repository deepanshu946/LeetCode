#define mod 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> temp(26,0);
        for(int i=0 ; i<s.length() ; i++){
            temp[s[i]-'a']++;
        }
        for(int i=0 ; i<t ; i++){
            vector<int> temp2(26,0);
            for(int j=0 ; j<26 ; j++){
                if(j != 25){
                    temp2[j+1] = temp[j]%mod;
                }
            }
            if(temp[25] != 0){
                temp2[0] += temp[25]%mod;
                temp2[1] += temp[25]%mod;
            }
            temp = temp2;
        }
        int ans = 0;
        for(int i=0 ; i<26 ; i++){
            ans = (ans + temp[i]%mod)%mod;
        }
        return ans%mod;
    }
};