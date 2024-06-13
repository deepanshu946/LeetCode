class Solution {
public:
    string frequencySort(string s) {
        // priority_queue<pair<int,char>> pq;
        // unordered_map<char,int> m;
        vector<pair<int,char>> arr(75,make_pair(0,0));

        for(int i=0 ;i<s.length() ; i++){
            char ch = s[i];
            arr[ch-48] = make_pair(arr[ch-48].first+1,ch);
        }
        // for(auto i:m){
        //     pq.push(make_pair(i.second,i.first));
        // }
        string ans = "";
        sort(arr.begin(), arr.end());
        reverse(arr.begin() , arr.end());
        for(int i=0 ; i<75 ; i++){
            pair<int,char> p= arr[i];
            while(p.first--){
                ans.push_back(p.second);
            }
        }
        // while(!pq.empty()){
        //     pair<int,char> top = pq.top();
        //     int i=top.first;
        //     while(i--){
        //         ans = ans + top.second;
        //     }
        //     pq.pop();
        // }
        return ans;
    }
};