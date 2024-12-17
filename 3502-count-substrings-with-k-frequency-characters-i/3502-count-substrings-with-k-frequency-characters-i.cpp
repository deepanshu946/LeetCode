class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char,int> m;
        int ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            for(int j=i ; j<s.length() ; j++){
                m[s[j]]++;
                if(m[s[j]] >= k){
                    ans = ans + s.length()-j;
                    m.clear();
                    break;
                }
            }
            m.clear();
        }
        return ans;
    }
};