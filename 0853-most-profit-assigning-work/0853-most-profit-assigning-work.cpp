class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // sort(profit.begin() , profit.end());
        int ans = 0;
        for(int i=0 ; i<worker.size() ; i++){
            int prof=0;
            int work = worker[i];
            for(int j=0 ; j<profit.size() ; j++){
                if(work>=difficulty[j]){
                    prof = max(prof,profit[j]);
                }
            }
            ans = ans+prof;
        }
        return ans;
  }
};