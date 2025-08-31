class Solution {
public:
    string strWithout3a3b(int a, int b) {
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        string ans = "";
        while(pq.size()>1){
            
            pair<int,char> t1 = pq.top();
            pq.pop();
            pair<int,char> t2 = pq.top();
            pq.pop();
            if(t1.first == t2.first){
                if(ans.size() != 0 && ans.back()=='a'){
                    int t = t1.first;
                    while(t != 0){
                        ans.push_back('b');
                        ans.push_back('a');
                        t--;
                        
                    }
                    return ans;
                }
                else{
                    int t = t1.first;
                    while(t != 0){
                        ans.push_back('a');
                        ans.push_back('b');
                        t--;
                        
                    }
                    return ans;
                }
            }
            else{
                if(t1.first > 1){
                    ans.push_back(t1.second);
                    ans.push_back(t1.second);
                    t1.first -= 2;
                }
                else{
                    ans.push_back(t1.second);
                    t1.first -= 1;
                }
                ans.push_back(t2.second);
                t2.first -= 1;
            }
            if(t1.first != 0){
                pq.push(t1);
            }
            if(t2.first != 0){
                pq.push(t2);
            }

        }
        if(!pq.empty()){
            for(int i=0 ; i<pq.top().first ; i++){
                ans.push_back(pq.top().second);
            }
        }
        return ans;


    }
};