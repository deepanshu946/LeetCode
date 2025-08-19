class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> m;
        vector<int> pre(s.length(),0);
        for(int i=0; i<s.length() ; i++){
            m.insert(s[i]);
            pre[i]=m.size();
        }
        m.clear();
        int count = 0;
        for(int i=s.length()-1 ; i>=1 ; i--){
            m.insert(s[i]);
            if(m.size()==pre[i-1]){
                count++;
            }
        }
        return count;

    }
};