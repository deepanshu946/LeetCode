class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0 ; i<s.length() ; i++ ){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        int ans = 0;
        for(auto i:m1){
            if(m2.find(i.first)==m2.end()){
                ans = ans + i.second;
            }
            else if(m2[i.first] < i.second){
                ans = ans - m2[i.first]+i.second;
            }
        }
        return ans;
    }
};