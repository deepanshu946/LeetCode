class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        for(int i=0 ; i<arr1.size() ; i++){
            m[arr1[i]]++;
        }
        vector<int> ans;
        for(int i=0 ; i<arr2.size() ; i++){
            int val = arr2[i];
            while(m[val] != 0){
                ans.push_back(val);
                m[val]--;
                if(m[val]==0){
                    m.erase(val);
                }
            }
        }
        for(auto i:m){
            while(i.second != 0){
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};