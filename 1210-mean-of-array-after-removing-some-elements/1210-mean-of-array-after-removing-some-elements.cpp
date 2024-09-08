class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int remove = n/20;
        sort(arr.begin(),arr.end());
        double size = n- remove - remove;
        double sum = 0;
        for(int i=remove ; i<n-remove ; i++){
            sum = sum + arr[i];
        }
        return sum/size;
    }
};