class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int ans = 0;
        int checkidx = n-1;
        int countzero = 0;
        for(int i=n-1 ; i>=0 ; i--){
            int idx = flips[i]-1;
            if(checkidx == i && countzero == n-checkidx-1){
                ans++;
            }
            if(idx <= checkidx){
                countzero++;
                checkidx = idx-1;
            }
            else{
                countzero++;
            }
            if(checkidx < 0){
                return ans;
            }
            
        }
        return ans;
        
        


    }
};