class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int> m;
        m.insert(spaces.begin(),spaces.end());
        string ans ="";
        for(int i=0 ; i<s.length() ; i++){
            if(m.count(i) !=0){
                ans.push_back(' ');
                m.erase(i);
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};