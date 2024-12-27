class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(int i=0 ; i<words2[0].length() ; i++){
            m1[words2[0][i]]++;
        }
        for(int i=1 ; i<words2.size(); i++){
            string temp = words2[i];
            for(int j=0 ; j<temp.length() ; j++){
            m2[temp[j]]++;
            }
            for(auto &k:m2){
                if(m1.find(k.first) != m1.end()){
                    m1[k.first]=max(k.second,m1[k.first]);
                }
                else{
                    m1[k.first]=k.second;
                }
            }
            m2.clear();
        }
        for(auto i:m1){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<string> ans;
        for(int i=0 ; i<words1.size() ; i++){
            string temp = words1[i];
            for(int j=0 ; j<temp.length() ; j++){
                m2[temp[j]]++;
            }
            bool flag = 1;
            for(auto k:m1){
                if(m2.find(k.first) != m2.end()){
                    if(m2[k.first] < k.second){
                        flag = 0;
                        break;
                    }
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag ){
                ans.push_back(temp);
            }
            m2.clear();
        }
        return ans;
    }
};