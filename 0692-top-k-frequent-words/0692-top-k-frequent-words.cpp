class Solution {
private:
struct compare{
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first==b.first)
                return a.second > b.second; //sort assending 
            return a.first<b.first; //sorts descending 
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string , int> m;
        for(int i=0 ; i<words.size() ; i++){
            m[words[i]]++;
        }
        //create a max heap with some modifications which will store the order of string in lexographically order
        priority_queue<pair<int,string> , vector<pair<int,string>> , compare> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        vector<string> ans;
        while(k--){
            pair<int,string> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        
        return ans;
    }
};