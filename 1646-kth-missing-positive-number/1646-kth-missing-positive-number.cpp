class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0 ; i<arr.size() ; i++){
            m[arr[i]]++;
        }
        int ans ;
        int i=1;
        while(k){
            if(m.find(i)==m.end()){
                ans = i;
                k--;
            }
            i++;
        }
        return ans;
    }
};