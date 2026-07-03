class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> freq;
        int maxi = 0;
        for(int i=0 ;i<nums.size() ; i++){
            freq[nums[i]]++;
            maxi = max(nums[i],maxi);
        }
        maxi = maxi + k;
        vector<int> diff(maxi+2,0);
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]-k < 0 ){
                diff[0]+=1;
            }
            else{
                diff[nums[i]-k]+=1;
            }
            diff[nums[i]+k+1]-=1;
        }
        // cout<<freq[0]<<endl;
        int ans = 0;
        for(int i=0 ; i<diff.size() ; i++){
            
            if(i!=0){
                diff[i] += diff[i-1];
            }   
            // cout<<diff[i]<<" ";/
            int count = min(diff[i]-freq[i],numOperations);
            // cout<<count<<endl;
            ans = max(ans ,count+freq[i]);
        }
        return ans;

    }
};