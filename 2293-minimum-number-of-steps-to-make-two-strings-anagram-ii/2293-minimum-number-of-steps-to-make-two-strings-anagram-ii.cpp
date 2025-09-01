class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(int i=0 ; i<s.length(); i++){
            m1[s[i]]++;
        }
        for(int i=0 ; i<t.length(); i++){
            m2[t[i]]++;
        }
        int ans = 0;
        for(auto i:m1){
            if(m2.find(i.first) != m2.end()){
                if(m2[i.first]<i.second){
                    ans += i.second-m2[i.first];
                    // m1[i.first]+= m2[i.first]-i.second;
                }
            }
            else{
                ans = ans + i.second;
                // m1[i.first]+=i.second;
            }
        }
        for(auto i:m2){
            if(m1.find(i.first) != m1.end()){
                if(m1[i.first]<i.second){
                    ans += i.second-m1[i.first];
                }
            }
            else{
                ans = ans + i.second;
            }
        }
        return ans;
        
    }
};