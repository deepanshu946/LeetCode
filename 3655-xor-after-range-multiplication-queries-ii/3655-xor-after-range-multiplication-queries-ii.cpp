#define mod 1000000007
class Solution {

public:
    long long power(long long a, long long b){
    if(b==0){
        return 1;
    }
    long long res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

    long long modInverse(long long x){
        return power(x, mod-2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int block = (sqrt(n));
        unordered_map<int,vector<vector<int>> > m;
        for(int i=0 ;i<queries.size() ; i++){
            int k= queries[i][2];
            if(k>=block){
                for(int j=queries[i][0] ; j<=queries[i][1] ; j+=k){
                    nums[j] =(1LL* nums[j]*queries[i][3])%mod;
                }
            }
            else{
                m[queries[i][2]].push_back(queries[i]);
            }

        }
        for(auto& i:m){
            vector<long long> diff(nums.size(),1);
            int k = i.first;
            // cout<<k<<endl;
            for(auto &j:i.second){
                diff[j[0]] = (diff[j[0]] * j[3]) % mod;
                int steps = (j[1]-j[0])/k;
                int next = j[0]+((steps+1)*k);
                if(next<nums.size()){
                    diff[next] = (diff[next] * power(j[3],mod-2)) % mod;
                }
            }
            for(int x=0 ; x<nums.size() ; x++){
                if(x-k>=0){
                    diff[x] = (diff[x] * diff[x-k]) % mod;
                }
                
            }
            for(int x=0; x<n ; x++){
                nums[x] = (1LL * nums[x] * diff[x]) % mod;
            }


        }
        int ans = 0;
        for(int i=0 ;i<nums.size() ;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};