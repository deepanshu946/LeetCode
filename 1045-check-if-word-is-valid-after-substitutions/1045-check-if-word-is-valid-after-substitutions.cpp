class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='c'){
                if(st.size() < 2){
                    return false;
                }
                char b = st.top();
                st.pop();
                char a = st.top();
                if(b=='b' && a=='a'){
                    st.pop();
                }
                else{
                    break;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};