class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<vector<int>,vector<char>> m;
        int len = votes[0].length();
        vector<vector<int>> temp(27 , vector<int>(len,0));
        for(int i=0 ; i<votes.size() ; i++){
            for(int j=0 ; j<votes[i].length() ; j++){
                int index = votes[i][j]-'A';
                temp[index][j]++;
            }
        }
        for(int i=0 ; i<temp.size() ; i++){
            for(int j=0 ; j<temp[i].size() ; j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }

        vector<int> zero(len,0);
        for(int i=0 ; i<27; i++){
            if(temp[i] != zero){
                m[temp[i]].push_back('A'+i);
            }
        }

        string ans="";
        for(auto i:m){
            sort(i.second.begin(),i.second.end());
            reverse(i.second.begin(),i.second.end());
            for(int j=0 ; j<i.second.size() ; j++){
                ans.push_back(i.second[j]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};