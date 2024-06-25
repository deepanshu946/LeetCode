class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> set;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (m.find(c1) != m.end()) {
                char mapping = m[c1];
                if (mapping != c2 ) {
                    return false;
                }
            } else {
                if(set.find(c2) != set.end()){
                    return false;
                }
                m[c1] = c2;
                set.insert(c2);
            }
        }
        return true;
    }
};