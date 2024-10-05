class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 1;
        int temp = capacity-plants[0];
        int n = plants.size();

        for(int i=0 ; i<n-1 ; i++){
            if(plants[i+1] <= temp){
                temp = temp-plants[i+1];
                ans = ans + 1;
            }
            else{
                ans = ans + (2*i+2);
                temp = capacity;
                i--;
            }
        }
        return ans;
    }
};