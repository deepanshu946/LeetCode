class Solution {
public:
    int countKeyChanges(string s) {
        if(s[0]>='A' && s[0]<='Z'){
                s[0]=s[0]-'A'+'a';
            }
        int ans =0;

        for(int i=1 ; i<s.length() ; i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
            if(s[i] != s[i-1]){
                ans++;
            }
        }
        
        return ans;

    }
};