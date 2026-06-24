class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int start = (n/2) - 1;
        int ans = 0;
        // unordered_map<int,int> m;
        vector<int> m(n,-1);
        for(int i=start ; i>=0 ; i--){
            int firstch = (i*2) + 1;
            int secondch = (i*2) + 2;
            // cout<<firstch<<" "<<secondch<<endl;
            int left = 0;
            int right = 0;
            if(m[firstch] == -1){
                left = cost[firstch];
                right = cost[secondch];
            }
            else{
                left = cost[firstch]+m[firstch];
                right = cost[secondch]+m[secondch];
            }
            ans = ans + abs(left-right);
            // cout<<max(left,right)<<endl;
            m[i]=max(left,right);
        }
        return ans;
    }
};