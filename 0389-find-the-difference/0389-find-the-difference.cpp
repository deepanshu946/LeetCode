class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        map<char,int> m; 
        for(int i=0 ; i<s.length() ; i++){
            char ch = s[i];
            m[ch]++;
        }
        for(int i=0 ; i<t.length() ; i++){
            char ch = t[i];
            if(m.find(ch)==m.end() || m[ch]==0){
                ans = ch;
            }
            else{
                m[ch]--;
            }
        }
        return ans;
    }
};