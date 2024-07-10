class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(int i=0 ; i<logs.size() ; i++){
            if(logs[i]=="../" ){
                if(ans!=0){
                    ans--;
                }
                    
            }
            else if(logs[i] != "./"){
                ans++;
            }

        }
        return ans;
    }
};