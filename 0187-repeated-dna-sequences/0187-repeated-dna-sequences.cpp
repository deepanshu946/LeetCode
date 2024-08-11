class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string temp = "";
        unordered_map<string,int> m;
        for(int i=0 ; i<10 ; i++){
            temp.push_back(s[i]);
        }
        m[temp]++;
        int left=0;
        int right = 10;
        while(right<s.length()){
            temp.erase(0,1);
            temp.push_back(s[right]);
            m[temp]++;
            right++;
        }
        vector<string> ans;
        for(auto i:m){
            if(i.second > 1){
                ans.push_back(i.first);
            }

        }
        return ans;

    }
};