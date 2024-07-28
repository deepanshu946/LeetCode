class Solution {
private:
    map<array<int,3> , int> m;
    int solve(int k, int i, int jump, int done) {
        if (i > k + 1 || i < 0) {
            return 0;
        }
        if (i<k+2 && jump<k+1 && m.find({i,jump,done}) != m.end()) {
            return m[{i,jump,done}];
        }
        int ans = 0;
        if(i==k){
            ans++;
        }
        if (done == 0) {
            ans += solve(k, i - 1, jump, 1);
        }
        ans += solve(k, i + pow(2,jump), jump + 1, 0);
        if(i<k+2 && jump<k+1){
            return m[{i,jump,done}]= ans;
        }
        else{
            return ans;
        }
    }

public:
    int waysToReachStair(int k) {
        return solve(k, 1, 0, 0);
    }
};