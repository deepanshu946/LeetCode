class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> s;
        int count = 0;
        for(int i=0 ; i<time.size() ; i++){
            if(s.find(abs(time[i]%60 - 60)) != s.end() ){
               
                count=count + s[abs(time[i]%60 - 60)];
            }
             if(time[i]%60==0 ){
                    count = count + s[0];
                }
            s[time[i]%60]++;
            // s.insert(abs(time[i]%60 - 60));

        }
        return count;
    }
};