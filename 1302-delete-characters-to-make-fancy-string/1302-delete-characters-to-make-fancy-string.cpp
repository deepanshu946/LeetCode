class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3){
            return s;
        }
        string ans = "";
        for(int i=0 ; i<s.length() ; i++){

            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
            }
                else{
                    ans.push_back(s[i]);
                }
                
            
        }
        return ans;
    }
};