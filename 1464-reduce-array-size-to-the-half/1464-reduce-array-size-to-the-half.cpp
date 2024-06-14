class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        int n = arr.size();
        for(int i=0 ; i<n ; i++){
            m[arr[i]]++;
        }
        for(auto i : m){
            pair<int,int> p = make_pair(i.second,i.first);
            pq.push(p);
        }
        int size = n;
        int ans=0;
        while(size > n/2){
            pair<int,int> top = pq.top();
            pq.pop();
            size = size - top.first;
            ans++;
        }
        return ans;
    }
};