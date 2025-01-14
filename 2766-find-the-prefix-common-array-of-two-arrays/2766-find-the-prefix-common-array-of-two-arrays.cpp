class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> ans;
        for(int i=0 ; i<a.size() ; i++){
            s1.insert(a[i]);
            s2.insert(b[i]);
            int temp = 0;
            for(auto i:s1){
                if(s2.find(i) != s2.end()){
                    temp++;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};