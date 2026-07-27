class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0 ; i<n ;i++){
            totalsum+=nums[i];
        }
        unordered_map<int,vector<int>> m1;
        for(int mask = 0 ; mask<(1<<(n/2)) ; mask++){
            int s = 0;
            int count = 0;
            for(int i=0 ; i<(n/2) ; i++){
                if(mask&(1<<i)){
                    count++;
                    s+=nums[i];
                }
            }
            m1[count].push_back(s);
        }
        unordered_map<int,vector<int>> m2;
        for(int mask = 0 ; mask<(1<<(n/2)) ; mask++){
            int s = 0;
            int count = 0;
            for(int i=(n/2) ; i<n ; i++){
                if(mask&(1<<(i-n/2))){
                    count++;
                    s+=nums[i];
                }
            }
            m2[count].push_back(s);
        }
        for(int i=0 ; i<=n/2 ; i++){
            sort(m2[i].begin(),m2[i].end());
        }
        int ans = INT_MAX; //abs(2*s1-s);

        for(int k=0 ; k<=n/2 ; k++){
            int leftelements = n/2 - k;
            for(auto leftsum :m1[k]){
                int requiredrightsum = (totalsum-2*leftsum)/2;
                int low = lower_bound(m2[leftelements].begin(),m2[leftelements].end(),requiredrightsum)-m2[leftelements].begin();
                if(low < m2[leftelements].size()){
                    int rightsum = m2[leftelements][low];
                    ans = min(ans , abs(2*(leftsum+rightsum)-totalsum));
                }
                if(low-1>=0){
                    int rightsum = m2[leftelements][low-1];
                    ans = min(ans , abs(2*(leftsum+rightsum)-totalsum));
                }
            }
        }
        return ans;




    }
};