class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int> m;
        for(int i=0 ; i<profit.size() ; i++){
            if(m.find(difficulty[i]) != m.end()){
            m[difficulty[i]]=max(m[difficulty[i]],profit[i]);

            }
            else{
                m[difficulty[i]]=profit[i];

            }
        }

        int ans = 0;
        for(int i=0 ; i<worker.size() ; i++){
            int prof=0;
            int work = worker[i];
            // for(int j=0 ; j<profit.size() ; j++){
            //     if(work>=difficulty[j]){
            //         prof = max(prof,profit[j]);
            //     }
            // }
            for(auto k:m){
                if(k.first>work){
                    break;
                }
                if(work>=k.first){
                    prof= max(prof,k.second);
                }
            }
            ans = ans+prof;
        }
        return ans;
  }
};