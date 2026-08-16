class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_set<char> st;
        for(int i=0 ; i<s.length() ; i++){
            if(m.find(s[i])==m.end()){
                if(st.find(t[i]) != st.end()){
                    return false;
                }
                m[s[i]]=t[i];
                st.insert(t[i]);


            }
            else{
                if(m[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};