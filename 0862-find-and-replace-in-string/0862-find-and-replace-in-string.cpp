class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,unordered_set<int>> m;
        for(int i=0 ; i<indices.size() ; i++){
            m[indices[i]].insert(i);
        }
        string ans = "";
        for(int i=0 ; i<s.length() ; i++){
            bool flag = 0;
            if(m.find(i) != m.end()){
                for(auto j:m[i]){
                    string src = sources[j];
                    string replace = targets[j];
                    string sub = s.substr(i,src.length());
                    if(sub==src){
                        ans=ans+replace;
                        cout<<replace<<endl;
                        i = i+src.length()-1;
                        flag=1;
                    }
                }
            }
            if(!flag){
                ans = ans + s[i];
            }
        }
        return ans;

    }
};