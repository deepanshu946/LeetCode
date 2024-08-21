class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        stack<char> s;
        for(int i=0 ; i<num.size() ; i++){
            char ch = num[i];
            if( !s.empty() && s.size()==1 && s.top()=='0' && ch=='0'){
                continue;
            }
            while(k != 0 && !s.empty() && s.top()-'0' > ch-'0'){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        while(ans.size()!=1 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(k != 0){
            while(!ans.empty() && k!=0){
                ans.pop_back();
                k--;
            }
        }
        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};