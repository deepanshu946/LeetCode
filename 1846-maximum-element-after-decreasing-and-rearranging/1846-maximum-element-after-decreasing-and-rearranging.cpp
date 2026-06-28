class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // unordered_set<int> s(arr.begin(),arr.end());
        int ans = 1;
        sort(arr.begin(),arr.end());
        int curr = 1;
        for(int i=1 ; i<arr.size() ; i++){
            if(abs(arr[i]-curr) > 1){
                curr++;
                ans++;
            }
            else{
                ans = arr[i];
            }

        }
        return ans;


    }
};