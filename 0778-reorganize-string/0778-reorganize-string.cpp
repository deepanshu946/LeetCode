class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,int>> pq;
        vector<int> temp(26,0);
        for(int i=0 ; i<s.length() ; i++){
            temp[s[i]-'a']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(temp[i] !=0){
            pq.push({temp[i],i});

            }
        }
        // return "";
        string ans="";
        while(!pq.empty()){
            pair<int,int> top1 = pq.top();
            pq.pop();
            if(pq.empty()){
                if(top1.first==1){
                    ans.push_back(top1.second+'a');
                    return ans;
                }
                else{
                    return "";
                }
            }
            pair<int,int> top2 = pq.top();
            
            pq.pop();
            ans.push_back(top1.second+'a');
            ans.push_back(top2.second+'a');
            if(top1.first != 1){
            pq.push({top1.first-1,top1.second});
            }
            if(top2.first != 1){
            pq.push({top2.first-1,top2.second});
            }

        }
        return ans;
    }
};