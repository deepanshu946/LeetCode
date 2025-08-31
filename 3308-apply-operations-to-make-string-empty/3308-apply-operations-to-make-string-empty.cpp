class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> temp(27,0);
        vector<int> temp2(27,0);
        int maxi = 0;
        for(int i=0 ; i<s.length() ; i++){
            temp[s[i]-'a']=i;
            temp2[s[i]-'a']++;
            maxi = max(maxi , temp2[s[i]-'a']);
        }
        vector<pair<int,char>> index;
        for(int i=0 ; i<temp2.size() ; i++){
            if(temp2[i]==maxi){
                index.push_back({temp[i],i});
            }
        }
        sort(index.begin(),index.end());
        string ans = "";
        for(int i=0 ; i<index.size(); i++){
            ans.push_back(index[i].second+'a');
        }
        return ans;


    }
};