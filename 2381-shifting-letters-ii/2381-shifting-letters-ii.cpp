class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> temp(s.length(),0);
        // cout<<
        for(int i=0 ; i<shifts.size() ; i++){
            if(shifts[i][2]==1){
                temp[shifts[i][0]] += 1;
                if(shifts[i][1] < s.length()-1 ){
                    temp[shifts[i][1]+1] -= 1;
                }
            }
            else{
                temp[shifts[i][0]] -= 1;
                if(shifts[i][1] < s.length()-1 ){
                    temp[shifts[i][1]+1] += 1;
                }
            }
        }
        for(int i=1 ; i<temp.size() ; i++){
            temp[i]+=temp[i-1];
        }
        for(int i=0 ; i<temp.size() ; i++){
            int x = s[i] - 'a';
            x += temp[i];
            x = ((x % 26) + 26) % 26;   // handles negative shifts
            s[i] = 'a' + x;
        }
        return s;
    }
};