class Solution {
private:
void pushall(unordered_set<int> &s , unordered_map<int,vector<int>> &m , int num){
    if(m.find(num) == m.end() ){
        return;
    }
    vector<int> temp = m[num];

    for(int i=0 ; i<temp.size() ; i++){
        bool flag=0;
        if(!s.count(temp[i])){
            flag=1;
            s.insert(temp[i]);
        }
        if(flag){
            pushall(s,m,temp[i]);
        }

    }
    return;

}
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
        unordered_set<int> s;
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<arr.size() ; i++){
            m[arr[i][0]].push_back(arr[i][1]);
        }
        s.insert(k);
        pushall(s,m,k);
        // for(auto i:s){
        //     cout<<i<<endl;
        // }
        for(auto& i:m){
            if(!s.count(i.first)){
                vector<int> temp = i.second;
                for(int j=0 ; j<temp.size() ; j++){
                    if(s.count(temp[j])){
                        s.clear();
                    }
                }
            }
        }
        // for(auto i:s){
        //     cout<<i<<endl;
        // }
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};