
class Solution {
private:
class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if (a.second <= b.second) {
            return true;
        }
        return false;
    }
};
public:
    int minimumIndex(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        unordered_map<int,int> m;
        vector<int> ltr(nums.size(),-1);
        vector<int> rtl(nums.size(),-1);

        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
            pq.push({nums[i],m[nums[i]]});
            pair<int,int> topp = pq.top();
            if(topp.second > (i+1)/2){
                ltr[i]=topp.first;
            }
        }
        m.clear();
        pq = priority_queue<pair<int,int>, vector<pair<int,int>>, Compare>(); // reset it

        
        m[nums[nums.size()-1]]++;
        for(int i=nums.size()-2 ; i>=0 ; i--){
                pq.push({nums[i+1],m[nums[i+1]]});
                pair<int,int> topp = pq.top();
                cout<<topp.second<<endl;
                if(topp.second > (nums.size()-i-1)/2){
                    rtl[i]=topp.first;
                }
            m[nums[i]]++;

        }
        for(int i=0 ; i<nums.size() ; i++){
            cout<<ltr[i]<<" "<<rtl[i]<<endl;
            if(ltr[i]==rtl[i] && ltr[i] != -1){
                return i;
            }
        }
        return -1;




        // pq.push({1,100});
        // pq.push({1,105});

        // pq.push({2,45});
        // pq.push({3,500});
        // while(!pq.empty()){
        // cout<<pq.top().first <<endl<<pq.top().second<<endl;
        // pq.pop();
        // }
        // return 0;

    }
};