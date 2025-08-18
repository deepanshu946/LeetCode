class comp{
    public:
    bool operator()(pair<int,int> &p1 , pair<int,int> &p2){
        if(p1.first != p2.first){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;
        // pq.push({2,3});
        // pq.push({1,2});
        // pq.push({2,4});
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        // return {};
        for(int i=0 ; i<arr.size() ; i++){
            int val = abs(arr[i]-x);
            pq.push({val,arr[i]});
            while(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};