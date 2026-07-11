class Solution {
public:
    string clearStars(string s) {
       priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
       for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='*'){
            pair<char,int> temp = pq.top();
            pq.pop();
            s[abs(temp.second)]='*';
        }
        else{
            pq.push({s[i],-i});
        }
       }
       string ans;
       for(int i=0 ; i<s.length() ; i++){
        if(s[i]!='*'){
            ans.push_back(s[i]);
        }
       }
        return ans;
    }
};