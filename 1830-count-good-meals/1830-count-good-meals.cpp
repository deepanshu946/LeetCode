class Solution {
public:
#define mod 1000000007
    int countPairs(vector<int>& nums) {
        unordered_set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(4);
        s.insert(8);
        s.insert(16);
        s.insert(32);
        s.insert(64);
        s.insert(128);
        s.insert(256);
        s.insert(512);
        s.insert(1024);
        s.insert(2048);
        s.insert(4096);
        s.insert(2*4096);
        s.insert(2*2*4096);
        s.insert(2*2*2*4096);
        s.insert(2*2*2*4096*2);
        s.insert(2*2*2*4096*2*2);
        s.insert(2*2*2*4096*2*2*2);
        s.insert(2*2*2*4096*2*2*2*2);
        s.insert(2*2*2*4096*2*2*2*2*2);
        s.insert(2*2*2*4096*2*2*2*2*2*2);
        unordered_map<int,int> m;
        long long ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        for(int i=0 ; i<nums.size() ; i++){
            int temp = nums[i];
            m[temp]--;
            if(m[temp]==0){
                m.erase(temp);
            }
            for(auto i:s){
                int temp2=i-temp;
                if(m.find(temp2) != m.end()){
                    // cout<<temp<<" "<<temp2<<endl;
                    ans=(ans+(m[temp2]));
                    // ans = ans %mod;
                }
            }
            m[temp]++;
        }
        return (ans/2)%mod;
    }
};