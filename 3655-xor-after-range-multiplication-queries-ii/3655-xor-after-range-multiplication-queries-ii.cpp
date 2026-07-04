#define mod 1000000007

class Solution {
public:
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int block = sqrt(n) + 1;

        unordered_map<int, vector<vector<int>>> mp;

        // Large k -> brute force
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= block) {
                for (int i = l; i <= r; i += k)
                    nums[i] = (1LL * nums[i] * v) % mod;
            } else {
                mp[k].push_back(q);
            }
        }

        // Small k
        for (auto &it : mp) {

            int k = it.first;

            vector<long long> diff(n, 1);

            for (auto &q : it.second) {

                int l = q[0];
                int r = q[1];
                long long v = q[3] % mod;

                diff[l] = (diff[l] * v) % mod;

                int nxt = l + ((r - l) / k + 1) * k;

                if (nxt < n)
                    diff[nxt] = (diff[nxt] * modInverse(v)) % mod;
            }

            // Process each remainder independently
            for (int rem = 0; rem < k; rem++) {

                long long cur = 1;

                for (int i = rem; i < n; i += k) {
                    cur = (cur * diff[i]) % mod;
                    nums[i] = (1LL * nums[i] * cur) % mod;
                }
            }
        }

        int ans = 0;
        for (int x : nums)
            ans ^= x;

        return ans;
    }
};