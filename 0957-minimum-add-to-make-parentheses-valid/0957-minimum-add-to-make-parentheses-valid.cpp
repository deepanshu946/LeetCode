class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    ans++;
                    // return ans;
                }
                else if( st.top()=='('){
                    st.pop();
                }
                else{
                    ans++;
                    st.pop();
                }
            }
        }
        ans = ans + st.size();

        return ans;
    }
};