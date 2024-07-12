class Solution {
private:
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()){
            return {};
        }
        vector<int> m(26,0);
        for(int i=0 ; i<p.length() ; i++){
            int val = p[i]-97;
            m[val]++ ;
        }
        vector<int> ans;
        for(int i=0 ; i<=s.length()-p.length() ; i++){
            vector<int> temp(26,0);
            for(int j=i ; j<p.length()+i ; j++){
                int val = s[j]-97;
                temp[val]++;
            }
            if(temp == m){
                ans.push_back(i);
            }
        }
        return ans;

    }
};