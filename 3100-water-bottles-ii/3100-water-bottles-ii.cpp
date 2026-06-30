class Solution {
public:
    int maxBottlesDrunk(int num, int ex) {
        int ans = num;
        while(num>=ex){
            num = num-ex;
            ex++;
            ans++;
            num++;
        }
        return ans;
    }
};