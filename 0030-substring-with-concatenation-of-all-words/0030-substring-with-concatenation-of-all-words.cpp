class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = words[0].length();
        int sl = s.length();
        if(sl<l){
            return {};
        }
        int k = sl%l;
        unordered_set<string> nochange;
        unordered_map<string,int> store;
        for(int i=0 ; i<words.size() ; i++){
            store[words[i]]++;
            nochange.insert(words[i]);
        }
        unordered_map<string,int> m;
        vector<int> ans;
        bool flag = 1;
        for(int i=0 ; i<l ; i++){
            int left = i;
            int right = i+(words.size()*l);
            int j=left;
            while(j<right){
                string temp = s.substr(j,l);
                m[temp]++;
                j=j+l;
            }
            while(right<s.length()){
                 flag = 1;
                for(auto j:store){
                    if(m.find(j.first)==m.end() || m[j.first]==0){
                    flag=0;
                    break;
                    }
                    if(m[j.first] != j.second){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(left);
                }
                string remove = s.substr(left,l);
                m[remove]--;
                string add = s.substr(right,l);
                m[add]++;
               
                left=left+l;
                right = right+l;
            }
            flag = 1;
            for(auto j:store){
                if(m.find(j.first)==m.end() || m[j.first]==0){
                flag=0;
                break;
                }
                if(m[j.first] != j.second){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.push_back(left);
            }
            m.clear();

        }
        return ans;
    }
};