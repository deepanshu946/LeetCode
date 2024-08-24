class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2 != 0 || cheeseSlices>tomatoSlices/2){
            return {};
        }
        int small = tomatoSlices/2;
        int left = small-cheeseSlices;
        if(left<0 || cheeseSlices-left<0){
            return {};
        }
        return {left,cheeseSlices-left};

    }
};