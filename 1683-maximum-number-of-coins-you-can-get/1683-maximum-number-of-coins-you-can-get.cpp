class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        if(n==3){
            return piles[1];
        }
        int front = 0;
        int end = n-1;
        int ans = 0;
        while(front < end){
            ans = ans + piles[end-1];
            end = end -2;
            front = front + 1;
        }
        return ans;

    }
};