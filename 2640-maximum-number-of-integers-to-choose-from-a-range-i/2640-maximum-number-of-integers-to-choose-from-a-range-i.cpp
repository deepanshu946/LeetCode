class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        int sum = 0;
        unordered_set<int> s(banned.begin(),banned.end());
        for(int i=1 ; i<=n ; i++){
            if(s.count(i) ==0){
                if(sum+i <= maxSum){
                    ans++;
                    sum = sum + i;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};