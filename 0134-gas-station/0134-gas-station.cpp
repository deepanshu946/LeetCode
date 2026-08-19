class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int total2 = 0;
        for(int i=0 ; i<gas.size() ; i++){
            total += gas[i];
            total2 += cost[i];
        }
        if(total2 > total){
            return -1;
        }
        int ans = 0;
        total = 0;
        for(int i=0 ; i<gas.size() ; i++){
            total += gas[i]-cost[i];
            if(total < 0){
                ans = i+1;
                total = 0;
            }
        }
        return ans;
    }
};