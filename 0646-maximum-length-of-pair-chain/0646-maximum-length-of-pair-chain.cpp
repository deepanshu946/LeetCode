class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , cmp);
        int count = 0;
        int end = INT_MIN;
        for(int i=0 ; i<pairs.size() ; i++){
            if(pairs[i][0]>end){
                count++;
                end = pairs[i][1];
            }
        }
        return count;
    }
};