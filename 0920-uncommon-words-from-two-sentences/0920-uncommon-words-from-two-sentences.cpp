class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m;
        string temp = "";
        for(int i=0 ; i<s1.length() ; i++){
            if(s1[i]==' ' ){
                m[temp]++;
                temp = "";
            }
            else{
                temp = temp + s1[i];
            }
        }
        m[temp]++;
        temp = "";
        for(int i=0 ; i<s2.length() ; i++){
            if(s2[i]==' ' ){
                m[temp]++;
                temp = "";
            }
            else{
                temp = temp + s2[i];
            }
        }
        m[temp]++;
        vector<string> ans;
        for(auto i:m){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};