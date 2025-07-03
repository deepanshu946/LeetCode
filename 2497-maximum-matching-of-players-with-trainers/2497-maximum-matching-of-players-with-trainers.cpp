class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
         sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int ans = 0;
        int i=0 ; 
        int j=0;
        while(i<g.size() && j<s.size()){
            while(j<s.size()){
                if(s[j] >= g[i]){
                    ans++;
                    j++;
                    break;
                }
                j++;


            }
            i++;
        }
        return ans;

    }
};