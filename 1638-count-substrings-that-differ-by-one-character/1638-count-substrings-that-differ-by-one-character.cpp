class Solution {
private:
    int solve(int i, int j, string s, string t, int n, int m) {
        if (i >= n) {
            return 0;
        }
        if (j == m) {
            return solve(i + 1, 0, s, t, n, m);
        }
        int ans =0;
        int x = i;
        int y = j;
        while (x < n && y < m && s[x] == t[y]) {
            x++;
            y++;
        }
        if (x == n || y == m)
            ans = 0;
        else {
            x++;
            y++;
            ans = 1;
            while (x < n && y < m && s[x] == t[y]) {
                ans++;
                x++;
                y++;
            }
        }
        return ans + solve(i, j + 1, s, t, n, m);
    }

public:
    int countSubstrings(string s, string t) {
        return solve(0, 0, s, t, s.length(), t.length());
    }
};