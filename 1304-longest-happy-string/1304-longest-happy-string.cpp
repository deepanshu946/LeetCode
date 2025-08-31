class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        string ans;
        while(true){
            pair<int,int> p = pq.top();
            pq.pop();
            pair<int,int> p2 = pq.top();
            pq.pop();
            if(p.first ==0 || p2.first==0){
                pq.push(p);
                pq.push(p2);
                break;
            }
            ans.push_back(p.second);
            p.first--;
            if(p.first>0){
            ans.push_back(p.second);
            p.first--;
            }
            if(p2.first >= p.first && p2.first > 1){
                ans.push_back(p2.second);
                ans.push_back(p2.second);
                p2.first = p2.first-2;
            }
            else{
                ans.push_back(p2.second);
                p2.first = p2.first-1;
            }
            pq.push(p);
            pq.push(p2);
        }
        pair<int,int> p = pq.top();
        if(p.first != 0 ){
            ans.push_back(p.second);
            if(p.first>1){
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};