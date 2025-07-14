class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> last(26,-1);
        vector<unordered_map<char,int>> m;
        unordered_map<char,int> temp;
        // return 0;
        for(int i=s.length()-1 ; i>=0 ; i--){
            if(last[s[i]-'a'] == -1){
                last[s[i]-'a']=i;
            }
            temp[s[i]]++;
            m.push_back(temp);
        }
        reverse(m.begin(),m.end());
        // for(int i=0 ; i<26 ; i++){
        //     cout<<last[i]<<" ";
        // }
        // for(int i=0 ; i<m.size() ; i++){
        //     for(auto i:m[i]){
        //         cout<<i.first<<"->"<<i.second<<endl;
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        vector<int> vis(26,-1);
        for(int i=0 ; i<s.length() ; i++){
            if(vis[s[i]-'a']==1){
                continue;
            }
            vis[s[i]-'a']=1;
            unordered_map<char,int> t;
            t=m[i];
            t[s[i]]--;
            if(t[s[i]]==0){
                t.erase(s[i]);
            }
            int lastindex = last[s[i]-'a'];
            if(lastindex <= i || lastindex == -1){
                continue;
            }
            unordered_map<char,int> t2=m[lastindex];
            for(auto j:t2){
                t[j.first] -= j.second;
                if(t[j.first]==0){
                    t.erase(j.first);
                }
            }
            ans = ans + t.size();
        }
        return ans;
    }
};