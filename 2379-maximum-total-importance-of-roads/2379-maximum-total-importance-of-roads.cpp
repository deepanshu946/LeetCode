class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> m;
        for (int i = 0; i < roads.size(); i++) {
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto i : m) {
            int city = i.first;
            int link = i.second;
            pair<int, int> p = make_pair(link, city);
            pq.push(p);
        }
        vector<int> importance(n);
        int currentImportance = n;
        while (!pq.empty()) {
            auto [count, city] = pq.top();
            pq.pop();
            importance[city] = currentImportance--;
        }
        long long ans = 0;
        for (const auto& road : roads) {
            ans += importance[road[0]] + importance[road[1]];
        }

        return ans;

    }
};