class Solution {
private:
int convert(string digit){
    int ans = 0;
    for(int i=0 ; i<digit.length() ; i++){
        ans = (ans*10)+(digit[i]-48);
    }
    return ans;
}
public:
    string decodeString(string s) {
        stack<string> st;
        int i=0;
        while(i<s.length()){
            if(s[i]==']'){
                string temp = "";
                while(st.top() != "["){
                    temp = temp+st.top();
                    st.pop();
                }
                st.pop();
                string digit = st.top();
                st.pop();
                int val = convert(digit);
                string final="";
                while(val--){
                    final = final+temp;
                }
                st.push(final);
            }
            else{
                if(s[i]>='0' && s[i]<='9'){
                    string digit="";
                    while(s[i]>='0' && s[i]<='9'){
                        digit = digit + s[i];
                        i++;
                    }
                    st.push(digit);
                    i--;
                }
                else{
                    string temp = "";
                    temp = s[i];
                    st.push(temp);
                }
            }
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};