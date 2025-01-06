class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char,char> m;
        for(char i=97 ; i<=122 ; i++){
            char temp = 122+97-i;
            m[i]=temp;
        }
        unordered_map<char,stack<int>> store;
        long long ans = 0;
        for(int i=0 ; i<s.length() ; i++){
            char mirror = m[s[i]];
            if(store.find(mirror)==store.end()){
                store[s[i]].push(i);
            }
            else{
                int temp = store[mirror].top();
                store[mirror].pop();
                if(store[mirror].size()==0){
                    store.erase(mirror);
                }
                ans = ans + (i-temp);
            }
        }
        return ans;

    }
};