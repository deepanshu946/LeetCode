class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> m;
        for(int i=0 ; i<s.length() ; i++){
            m[s[i]]++;
        }
        int distinct = m.size();
        unordered_set<char> alreadyinstack;
        stack<char> st;
        for(int i=0 ; i<s.length() ; i++){
            m[s[i]]--;
            if(alreadyinstack.count(s[i])){
                continue;
            }

            while(!st.empty() && st.top() >= s[i] && m[st.top()]>=1){
                alreadyinstack.erase(st.top());
                st.pop();
            }

            if(alreadyinstack.find(s[i])==alreadyinstack.end()){
                st.push(s[i]);
                alreadyinstack.insert(s[i]);
            }

        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};