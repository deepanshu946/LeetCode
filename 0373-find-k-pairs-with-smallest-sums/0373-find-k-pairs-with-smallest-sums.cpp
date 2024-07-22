class Solution {
public:
struct compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.first+a.second < b.first+b.second; // Max heap: a should be placed before b if a is smaller
    }
};

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<vector<int>> ans;
        bool flag=0;
        for(int i=0 ; i<nums1.size() ; i++){
            for(int j=0 ; j<nums2.size() ; j++){
                int val = nums1[i]+nums2[j];
                if(pq.empty()){
                    pq.push({nums1[i],nums2[j]});
                }
                else{
                    pair<int,int> p = pq.top();
                    int temp = p.first+p.second;
                    if(pq.size()==k && temp>val){
                        pq.pop();
                        pq.push({nums1[i],nums2[j]});
                    }
                    else if(pq.size()<k){
                        pq.push({nums1[i],nums2[j]});
                    }
                    else if(temp<=val){
                        break;
                        flag=1;
                    }
                }
            }
            if(flag){
                break;
            }
        }
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back({p.first,p.second});
        }
        return ans;


    }
};