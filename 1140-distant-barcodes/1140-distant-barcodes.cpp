class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
         priority_queue<pair<int,int>> pq;
         for(auto i:m){
            pq.push({i.second,i.first});
         }
        vector<int> ans;
        while(pq.size() != 0){
            bool flag = 0;
            pair<int,int> temp = pq.top();
            pq.pop();
            pair<int,int> temp2 ;
            if(!pq.empty()){
                  temp2 = pq.top();
                pq.pop();
                flag = 1;
            }
           
            ans.push_back(temp.second);
            if(flag==1)
                ans.push_back(temp2.second);

            temp.first--;
            if(flag==1)
                temp2.first--;

            if(temp.first != 0){
                pq.push(temp);
            }
            if(flag==1 && temp2.first != 0){
                pq.push(temp2);
            }

        }
        return ans;
    }
};