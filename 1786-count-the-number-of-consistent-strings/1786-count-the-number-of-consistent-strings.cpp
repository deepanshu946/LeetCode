class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        s.insert(allowed.begin() , allowed.end());
        int ans = 0;
        for(int i=0 ; i<words.size() ; i++){
            bool flag = 1;
            for(int j=0 ; j<words[i].length() ; j++){
                if(s.find(words[i][j]) == s.end()){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};