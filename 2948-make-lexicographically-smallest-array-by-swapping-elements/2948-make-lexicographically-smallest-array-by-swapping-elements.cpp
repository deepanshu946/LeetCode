class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> temp;
        for(int i=0 ; i<nums.size() ; i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,multiset<int>> m; // grp -> elements
        unordered_map<int,int> m2;// index -> grp
        int grp = 1;

        for(int i=0 ; i<temp.size() ; i++){
            if(i==0){
                m2[temp[i].second]=grp;
                m[grp].insert(temp[i].first);
            }
            else{
                if(abs(temp[i].first - temp[i-1].first) <= limit ){
                    m2[temp[i].second]=grp;
                    m[grp].insert(temp[i].first);
                }
                else{
                    grp++;
                    m2[temp[i].second]=grp;
                    m[grp].insert(temp[i].first);
                }
            }
        }
        vector<int> ans(nums.size(),0);
        for(int i=0 ; i<nums.size() ; i++){
            int group = m2[i];
            int elem = *m[group].begin();
            m[group].erase(m[group].find(elem));
            ans[i]=elem;
        }
        return ans;
       
    }
};