class Solution {
private: 
long long global = LLONG_MIN;

long long solve(vector<long long> &temp, unordered_map<int , int> &m, vector<int> &nums , int k){
    long long val = LLONG_MIN;
    long long tempval = 0;
    for(int i=0 ; i<temp.size() ; i++){
        tempval = tempval + temp[i];
        // cout<<tempval<<endl;
        if(tempval<0){
            tempval=0;
        }
        val = max(val,tempval);
    }
    for(int i=0 ; i<temp.size() ; i++){
        int idx = m[i];
        if(idx+1 >= nums.size()){
            temp.pop_back();
        }
        else{
            temp[i] = temp[i] - nums[idx-k+1];
            temp[i] +=  nums[idx+1];
            global = max(global , temp[i]);
            m[i] += 1;
        }
        
    }
    return val;
}
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        // for(int i=0 ; i<k ; i++){
        unordered_map<int,int> m;
        vector<long long> temp;
        int size = 0;
        long long store = 0;
        for(int j=0 ; j<nums.size() ; j++){
            store +=  nums[j];
            size++;
            if(size==k){
                m[temp.size()]=j;
                global = max(global , store);
                temp.push_back(store);
                store = 0;
                size = 0;
            }
            
        }

            // ans = max(ans , solve(temp));
        // }
        // cout<<global<<endl;

        for(int i=0 ; i<k ; i++){
            ans= max(ans , solve(temp,m, nums,k));
        }

        
        if(ans==0)return global;
        return ans;
    }
};