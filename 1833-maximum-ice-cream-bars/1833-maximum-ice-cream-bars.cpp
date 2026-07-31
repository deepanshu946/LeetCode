class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = 0;
        for(int i=0 ; i<costs.size() ; i++){
            maxi= max(maxi,costs[i]);
        }
        vector<int> temp(maxi+1,0);
        for(int i=0 ; i<costs.size() ; i++){
            temp[costs[i]]++;
        }
        for(int i=1; i<temp.size() ; i++){
            temp[i]=temp[i]+temp[i-1];
        }
        vector<int> ans(costs.size(),0);
        for(int i=0 ; i<costs.size() ; i++){
            ans[temp[costs[i]]-1]=costs[i];
            temp[costs[i]]--;
        }
        int count = 0;
        for(int i=0 ; i<ans.size() ; i++){
            if(coins<ans[i]){
                break;
            }
            count++;
            coins = coins - ans[i];
        }
        return count;
    }
};