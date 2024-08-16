class Solution {
public:
    int countAsterisks(string s) {
        bool ast=0;
        int ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='|' ){
                ast=!ast;
            }
            if(s[i]=='*' && ast==0){
                ans++;
            }
        }
        return ans;
    }
};