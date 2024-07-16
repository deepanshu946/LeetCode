class Solution {
public:
    int countKeyChanges(string s) {
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        int ans =0;
        for(int i=1 ; i<s.length() ; i++){
            if(s[i] != s[i-1]){
                ans++;
            }
        }
        return ans;

    }
};