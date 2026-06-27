class Solution {
private:
// vector<int> sieve(int n) {
    
//     // creation of boolean array
//     vector<bool> prime(n + 1, true);
//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p] == true) {
            
//             // marking as false
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
    
//     vector<int> res;
//     for (int p = 2; p <= n; p++){
//         if (prime[p]){ 
//             res.push_back(p);
//         }
//     }
//     return res;
// }

public:
    int primeSubarray(vector<int>& nums, int k) {
        multiset<int> s;
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<bool> prime(50001, true);
        // cout<<prime[9551]<<endl;
        // cout<<prime[41039]<<endl;
        prime[1]=0;
        for (int p = 2; p * p <= 50000; p++) {
            if (prime[p] == true) {
                
                // marking as false
                for (int i = p * p; i <= 50000; i += p)
                    prime[i] = false;
            }
        }
        deque<pair<int,int>> primes;   // {index, value}
        while(right<nums.size()){
            if(prime[nums[right]]){
                s.insert(nums[right]);
                primes.push_back({right,nums[right]});
                if(s.size()>=2){
                    // cout<<*s.begin()-*s.rbegin()<<endl;
                    
                    while(abs(*s.begin()-*s.rbegin()) > k){
                        if(prime[nums[left]]){
                            s.erase(s.find(nums[left]));
                            primes.pop_front();  
                        }
                        left++;
                    }
                    
                }
            }
            if(primes.size() >= 2){
                // ans++;
                int secondLastPrimeIndex = primes[primes.size() - 2].first;
                ans += secondLastPrimeIndex - left + 1; 

            }
            right++;
        }
        // if(abs(*s.begin()-*s.rbegin()) <= k){
        //     // ans++;
        //     int secondLastPrimeIndex = primes[primes.size() - 2].first;
        //     ans += secondLastPrimeIndex - left + 1; 

        // }
        return ans;
    }
};