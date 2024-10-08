class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& str) {
        unordered_set<string> s;
        s.insert(str.begin(),str.end());
        int count = 0;
        for(int i=0 ; i<message.size() ; i++){
            if(s.count(message[i])){
                // s.erase(message[i]);
                count++;
            }
            if(count>=2){
                return true;
            }
        }
        return false;
    }
};