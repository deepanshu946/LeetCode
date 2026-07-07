class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        unordered_map<char, int> m;
        for (int i = 0; i < str2.length(); i++) {
            m[str2[i]]++;
        }
        unordered_map<char, int> m2;
        for (int i = 0; i < str1.length(); i++) {
            m2[str1[i]]++;
        }
        for (auto i : m) {
            if (m2.find(i.first) != m2.end()) {
                if (m2[i.first] >= i.second) {
                    m2[i.first] = m2[i.first] - i.second;
                } else {
                    i.second -= m2[i.first];
                    m2.erase(i.first);
                    char newchar = i.first - 1;
                    if (i.first == 'a') {
                        newchar = 'z';
                    }
                    if (m2.find(newchar) == m2.end()) {
                        return false;

                    } else {
                        if (m2[newchar] < i.second) {
                            return false;
                        } else {
                            m2[newchar] -= i.second;
                        }
                    }
                }
            } else {
                char newchar = i.first - 1;
                if (i.first == 'a') {
                    newchar = 'z';
                }
                if (m2.find(newchar) == m2.end()) {
                    return false;

                } else {
                    if (m2[newchar] < i.second) {
                        return false;
                    } else {
                        m2[newchar] -= i.second;
                    }
                }
            }
        }
        return true;
    }
};